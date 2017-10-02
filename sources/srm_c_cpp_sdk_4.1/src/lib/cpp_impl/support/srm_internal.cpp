/*
 * SRM API
 *
 * FILE       : srm_internal.cpp
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *
 * DESCRIPTION:
 *   This file is internal to the SRM API.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 * - SRM spec. 4.1
 *
 * For other release dates/detailed changes, contact SRI or SAIC.
 */

/*
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include "srm_internal.h"
#include "srm_sincos.h"

/*
 * CONST: SRM_PI
 */
const SRM_Long_Float SRM_PI = (SRM_Long_Float)SRM_PI_DEFINE;
const SRM_Long_Float SRM_2_PI =(SRM_Long_Float) SRM_2_PI_DEFINE;

const SRM_Long_Float SRM_PI_DIV_4=(SRM_Long_Float)SRM_PI_DIV_4_DEFINE;
const SRM_Long_Float SRM_PI_DIV_2=(SRM_Long_Float)SRM_PI_DIV_2_DEFINE;

const SRM_Long_Float SRM_1_DIV_ROOT_2=(SRM_Long_Float)SRM_1_DIV_ROOT_2_DEFINE;

/*
 * CONST: SE_DEGREES_PER_RADIAN = 180.0 / SE_PI
 */
const SRM_Long_Float SRM_DEGREES_PER_RADIAN = (SRM_Long_Float)SRM_DEGREES_PER_RADIAN_DEFINE;


/*
 * CONST: SRM_RADIANS_PER_DEGREE = SRM_PI / 180.0
 */
const SRM_Long_Float SRM_RADIANS_PER_DEGREE = (SRM_Long_Float)SRM_RADIANS_PER_DEGREE_DEFINE;

/*
 * CONST: SRM_METRES_PER_FOOT
 *
 *   0.3048 is an *exact* conversion factor from feet to metres
 */
const SRM_Long_Float SRM_METRES_PER_FOOT = (SRM_Long_Float)SRM_METRES_PER_FOOT_DEFINE;

/*
 * CONST: SRM_FEET_PER_METRE = 1.0 / SRM_METRES_PER_FOOT
 */
const SRM_Long_Float SRM_FEET_PER_METRE = (SRM_Long_Float)SRM_FEET_PER_METRE_DEFINE;


/*! returns NaN to indicate failure.
 * NaN is normally processor dependent but defining
 * a macro here to the C library call strtod that is
 * guaranteed to produxce it ensures that we get it right always
 */
const SRM_Long_Float IMPL_NAN=strtod("NAN", (char**) 0);


SRM_Integer_Unsigned IMPL_GOODSTAT=(IMPL_VALID|
                                    IMPL_EXTENDED|
                                    IMPL_DEFINED);

SRM_Integer_Unsigned IMPL_BADSTAT= (IMPL_FPE|
                                    IMPL_ILLEGL|
                                    IMPL_INACTBLE|
                                    IMPL_UNIMPLEM|
                                    IMPL_MEMALLOC|
                                    IMPL_SRFSRC|
                                    IMPL_OBJSRC|
                                    IMPL_BADORM|
                                    IMPL_CRDORG|
                                    IMPL_CRDDST|
                                    IMPL_INVALID);

/*Avoided the floor function here as on intel P I-III it is painfully slow.  The truncation
  to int is still not that great and it could easily consume most of the time
  in this function but assembler is out of the question. . .  modf is best on
  Ultrasparc and PIII*/


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION delta_lambda_min
 *
 * This function returns the absolute value of the smallest change in longitude
 * difference between two values of longitude.  It is used because it
 * is difficult to get right the test for within range or not in UTM and TM
 *
 *-----------------------------------------------------------------------------
 */
SRM_Long_Float delta_lambda_min
(
    SRM_Long_Float lambda1,
    SRM_Long_Float lambda2
)
{
    SRM_Long_Float simple_difference;
    if(lambda2>=lambda1)
    {
        simple_difference=lambda2-lambda1;
        if(fabs(simple_difference)>=SRM_PI)
        {
            return fmod((SRM_2_PI-lambda2)+lambda1,SRM_2_PI);
        }
        else
        {
            return simple_difference;
        }
    }
    else
    {
        simple_difference=lambda1-lambda2;
        if(fabs(simple_difference)>=SRM_PI)
        {
            return fmod((SRM_2_PI-lambda1)+lambda2,SRM_2_PI);
        }
        else
        {
            return simple_difference;
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_LTP_Rotation_Matrix_T
 *
 * This function calculates the LTP rotation matrix from the
 * LTP Generating Function G=D+Tp  Where D is a displacement
 * from R{3} origin and T is a rotation matrix which rotates
 * points, vectors. and matrices to be aligned with the R{3}
 * axes instead of in the Local Tangent Plane System
 * T is a 4x4 matrix to accomodate usage of homogenous coordinates
 * although this function implements no translations.
 *
 * Lambda is celestiodetic longitude
 * Phi is    celestiodetic latitude
 * alpha  is LTP azimuth
 *
 * Source is PDB: LTPxfer01.doc 11/18/2002
 *
 *----------------------------------------------------------------------------
 */
void
SRM_LTP_Rotation_Matrix_T
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float lambda,
    SRM_Long_Float phi,
    SRM_Long_Float alpha
)
{
    SRM_Long_Float cl, cp, ca, sa, sp, sl;

    srm_sincos( lambda, sl, cl);
    srm_sincos( phi, sp, cp );
    srm_sincos( alpha, sa, ca );

    T[0][0]= -sl * ca + cl * sp * sa;
    T[0][1]= -sl * sa + -cl *sp *ca;
    T[0][2]=  cl * cp;
    T[0][3]=  0.0;

    T[1][0]= cl * ca + sl * sp * sa;
    T[1][1]= cl * sa + -sl * sp * ca;
    T[1][2]= sl * cp;
    T[1][3]= 0.0;

    T[2][0]= cp * -sa;
    T[2][1]= cp *  ca;
    T[2][2]= sp;
    T[2][3]= 0.0;

    T[3][0]= 0.0;
    T[3][1]= 0.0;
    T[3][2]= 0.0;
    T[3][3]= 1.0;
} /* end SRM_LTP_Rotation_Matrix_T */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_LTP_Rotation_Matrix_T_notrig
 *
 *   Version of matrix generator that assumes all trig is done in advance
 *
 *----------------------------------------------------------------------------
 */
void SRM_LTP_Rotation_Matrix_T_notrig
(
    IMPL_Matrix_4x4 *T,
    SRM_Long_Float   sl,
    SRM_Long_Float   cl,
    SRM_Long_Float   sp,
    SRM_Long_Float   cp,
    SRM_Long_Float   sa,
    SRM_Long_Float   ca
)
{
    T->mat[0][0]= -sl * ca + cl * sp * sa;
    T->mat[0][1]= -sl * sa + -cl *sp *ca;
    T->mat[0][2]=  cl * cp;
    T->mat[0][3]=  0.0;

    T->mat[1][0]= cl * ca + sl * sp * sa;
    T->mat[1][1]= cl * sa - sl * sp * ca;
    T->mat[1][2]= sl * cp;
    T->mat[1][3]= 0.0;

    T->mat[2][0]= cp * -sa;
    T->mat[2][1]= cp *  ca;
    T->mat[2][2]= sp;
    T->mat[2][3]= 0.0;

    T->mat[3][0]= 0.0;
    T->mat[3][1]= 0.0;
    T->mat[3][2]= 0.0;
    T->mat[3][3]= 1.0;
} /* end SRM_LTP_Rotation_Matrix_T_notrig */


/***********************************************************************/

const SRM_Long_Float Impl_Identity_Matrix4x4[4][4]=
{
    {1.0,0.0,0.0,0.0},
    {0.0,1.0,0.0,0.0},
    {0.0,0.0,1.0,0.0},
    {0.0,0.0,0.0,1.0},
};


/* Generalized Functions Start Here*/


/*
 *-------------------------------------------------------------------------
 *
 * det performs determinant computation using expansion by minors
 * For simplicity of understanding, this routine makes copies
 * of the increasingly small matrices as an expedient.  It is designed
 * primarily for use in data validation in initializations.  My references
 * suggest that converting the matrix to an upper triangular matrix
 * is a better strategy for large matrices but the LUP decomposition
 * algorithm here used to make upper triangular matrixes might belch if
 * it is fed a singular matrix which this simple determinant computation
 * is used to prevent.
 *
 * A is expected to be a pointer ot the first location of an nxn matrix
 *
 * rank is expected to be n.
 *
 *-------------------------------------------------------------------------
 */
double
_det
(
    const double *A,
    const int     rank
)
{
    double d=0.0;
    if(rank==2)
    {
        d= A[0]*A[3]-A[1]*A[2];
    }
    else
    {
        int i;
        for(i=0; i<rank; i++)
        {
            double* B = (double*)malloc((rank-1)*(rank-1)*sizeof(double));
            if (B==0)
            {
                d=IMPL_NAN;
                /*This is to invalidate the results in case of error since
                 * IMPL_NAN will turn any calculation involving it to IMPL_NAN
                 */
                return d;
            }
            else
            {
                int k,l, index=0;
                for(k=0;k<rank;k++)
                {
                    for(l=1;l<rank;l++)
                    {
                        if(k!=i)
                        B[index++]=(*(A+rank*k+l));
                    }
                }
                d+=((i%2)?(-1):(1)) * (*(A+(i*rank))) * Impl_det(B,rank-1);
                free(B);
            }
        }
    }
    return d;
}

/*
 *-------------------------------------------------------------------------
 *
 * lup_decompose works in place on A modifying the entries on
 * the diagonal and above to be an upper triangular matrix,
 * the entries below the diagonal to be a lower triangular matrix
 * and pi_matrix to be a list of the necessary permutations.
 *
 * A is a pointer to the first entry in the matrix
 * pi_matrix is a pointer to the first entry of an array of integers
 *  of equal rank to the matrix
 * rank is the rank of the matrix and the pi_matrix.
 *
 *-------------------------------------------------------------------------
 */
int lup_decompose
(
          double *A,
          int    *pi_matrix,
    const int     rank
)
{
    int i, j, k, k_prime=0;
    double p;

#if 1
  /* We're assuming that the caller has checked the parameters
   * as this code is intended for internal use.  Activate this
   * test to validate input*/

    if (IS_SINGULAR(A, rank))
    {
        return -1;

        /* If the determinant of the matrix is almost zero
         * then we will bail here because the problem isn't
         * well behaved and the algorithm needs a non-singular
         * matrix to avoid division by zero
         */
    }
#endif

  /* Initialize the permutation matrix representation.
   * The permutation matrix is represented here by storing the
   * column number containing a 1 of the row represented by the index
   */
    for(i=0; i< rank ;++i)
    {
        pi_matrix[i]=i;
    }


  /* searches A matrix for the largest absolute value
   * to be used as a pivot
   */
    for(k=0; k<rank;++k)
    {
        p=0.0;

        for(i=k; i<rank; ++i)
        {
            double fabs_aik= fabs( *(A+(i*rank)+k));
            if (fabs_aik >p)
            {
                p=fabs(fabs_aik);
                k_prime=i;  /* store The row of the largest absolute value*/
            }
        }

      /* Swaps the last processed row with the row with the largest value
       * in the permutation matrix
       */
        {
            int tmp;
            tmp=pi_matrix[k];
            pi_matrix[k]=pi_matrix[k_prime];
            pi_matrix[k_prime]=tmp;
        }

      /* Swaps the values of the last row with the biggest row*/

        for(i=0; i<rank; ++i)
        {
            double tmp;
            tmp=*(A+(k*rank)+i);
            *(A+(k*rank)+i)=*(A+(k_prime*rank)+i);
            *(A+(k_prime*rank)+i)=tmp;
        }
        {
            /* Divides the row by the value on the diagonal
             * to reduce the value on the diagonal to a one*/
            double Akk_inv=1.0/ *(A+(k*rank)+k);
            for(i=k+1; i<rank ;++i)
            {
                *(A+(i*rank)+k)*=Akk_inv;
                /*reduction in strength optimization
                 *precomputes divide above
                 */
                for(j=k+1; j<rank; ++j)
                {
                    *(A+(i*rank)+j)-=(*(A+(i*rank)+k))*(*(A+(k*rank)+j));
                }
            }
        }
    }
    return 0;
}


/*
 *-------------------------------------------------------------------------
 *
 * lup_solve returns column vectors solving Ax=b placing the answer
 * in the one dimensional array specified by x which is passed
 * by reference. pi_matrix represents a permutation matrix used to
 * place the vectors in the proper order though it only stores the column
 * where a one should be present to effect the necessary permutation.
 *
 * A is a pointer ot the first value in an nxn matrix
 * Pi_matrix is a pointer to the first value in a 1 dim array of integers of
 *           length rank
 * b is a pointer to the first value of a column vector stored as a 1 dim
 *           array of length rank
 * x is an array of pointer to pointers which specifies the location that
 *
 *-------------------------------------------------------------------------
 */
int lup_solve
(
          double  *A,
          int     *pi_matrix,
    const double  *b,
          double **x,
    const int      rank
)
{
    int i, j, status=-1;
    double* y= (double*) calloc((size_t)rank,sizeof(double));

   /*
    * Interprets A as a lower triangular matrix
    * with permutation matrix pi_matrix.  Zeroes out
    * the coefficients starting with the upper
    * right corner where the coefficient is already 1
    * from the decomposition
    */
    if (y==0)
    {
        status=-1;
    }
    else
    {
        y[0]=0.0;
        for(i=0; i<rank; ++i)
        {
            double summation=0;
            for(j=0; j<i  ; ++j)
            {
                summation+=  *(A+(rank*i)+j)*y[j];
            }
            y[i]=b[pi_matrix[i]]-summation;
        }

      /*
       * Interprets A as an upper triangular matrix and works from
       * the bottom right where the coefficient is k but there
       * are no additive terms.
       * This section back substitutes y values from the lower triangular
       * matrix to get x values for the whole matrix.
       */
        *x[0]=0.0;

        for(i=(rank-1); i>=0; --i)
        {
            double summation=0;
            for(j=i+1; j<rank; ++j)
            {
                summation+= *(A+(rank*i)+j) * (*x[j]);
            }
            *x[i]=(y[i]-summation)/ *(A+rank*i+i);
        }
        free(y);
    }
    return status;
}


/* Generalized Invert Routine*/

/* invert performs matrix inversion for an nxn matrix
 * A is a pointer to the first element of an nxn matrix
 * A_inv is a pointer to space which will be initialized to A_inv
 * rank is the number of rows in a column of the square nxn matrix
 */
int _invert
(
    const double *A,
          double *A_inv,
    const int     rank
)
{
    int     status=-1;  /*Set failure as a default*/
    /* The identity matrix */
    double *I=(double*)calloc((size_t)(rank*rank),sizeof(double));

  /* The Permutation Matrix*/
    int* pi_matrix=(int*)calloc((size_t)rank,sizeof(int));

    double* C=(double*)calloc((size_t)(rank*rank),sizeof(double));

  /*This sets up pointers that allow us to place the answers
   *in the form of the matrix A_inv since the solver returns column
   *vectors in c array rows but c stores arrays by rows and not columns
   */

    double** x=(double**)calloc((size_t)(rank*rank),sizeof(double*));
  /*X is an array of pointers to pointers to doubles.
   *due to the way that the solver calculation is done,
   *the result ends up transposed.  We use x as pointers to
   *pointers so that the result can be placed into A_inv,
   *its actual storage location on computation instead of computing and
   *copying into its final location later
   */
    PRINT_MATRIX(A,rank);

    if (!((I==0)         ||
          (pi_matrix==0) ||
          (C==0)         ||
          (x==0)
         )
      )
    {
        /*No memory failure, the normal case*/
        /* initialize the xpointers as well as the Identity matrix*/
        int i,j,index=0;

        for(i=0;i<rank;i++)
        {
            for(j=0;j<rank;j++)
            {
                x[index++]= (A_inv+(j*rank)+i);
                if(i==j)
                    *(I+(i*rank)+j)=1;
            }
        }

      /* Copy the data passed to us
         so that we don't overwrite it*/
        memcpy(C,A,rank*rank*sizeof(double));

        PRINT_MATRIX(C, rank);

        status=lup_decompose(C, pi_matrix , rank);

        if (status != -1)
        {
            PRINT_MATRIX(C, rank);

            for (i=0; i<rank; i++)
            {
              /*We can use I[i] here because the identity matrix is
                equal to its transpose*/

                lup_solve(C, pi_matrix, I+i*rank, x+i*rank, rank);
            }
            status=0;
        }
        free(I);
        free(pi_matrix);
        free(C);
        free(x);
    }
    else
    {
        /* One or more memory allocations failed*/
        status=-1;
        if(I!=0)
            free(I);
        if(pi_matrix!=0)
            free(pi_matrix);
        if(C!=0)
            free(C);
        if(x!=0)
            free(x);
    }
    return status;
}

void
_transpose
(
    const double *A,
          double *A_t,
    const int     rank
)
{
    int i, index=0, j;

    for(i=0;i<rank;i++)
    {
        for(j=0;j<rank;j++)
        {
            A_t[index++]= *(A+(j*rank)+i);
        }
    }
}

void _dot_product
(
    const SRM_Long_Float *A,
    const SRM_Long_Float *B,
          SRM_Long_Float *result
)
{
    int i;

    *result=0.0;

    for(i=0;i<3;i++)
        *result = *result + (A[i] * B[i]);
}

void _cross_product
(
    const SRM_Long_Float *A,
    const SRM_Long_Float *B,
          SRM_Long_Float *result
)
{
    result[0] = A[1] * B[2] - A[2] * B[1] ;
    result[1] = A[2] * B[0] - A[0] * B[2] ;
    result[2] = A[0] * B[1] - A[1] * B[0] ;
}


/*
 * FUNCTION: _matrix_multiply4x4
 *
 *   Hard coded matrix multiply that does no error checking.
 *   For internal implementation use
 */
void _matrix_multiply4x4
(
    SRM_Long_Float A[4][4],
    SRM_Long_Float B[4][4],
    SRM_Long_Float C[4][4]
)
{
    C[0][0]=
      A[0][0] * B[0][0]+
      A[0][1] * B[1][0]+
      A[0][2] * B[2][0]+
      A[0][3] * B[3][0];

    C[1][0]=
      A[1][0] * B[0][0]+
      A[1][1] * B[1][0]+
      A[1][2] * B[2][0]+
      A[1][3] * B[3][0];

    C[2][0]=
      A[2][0] * B[0][0]+
      A[2][1] * B[1][0]+
      A[2][2] * B[2][0]+
      A[2][3] * B[3][0];

    C[3][0]=
      A[3][0] * B[0][0]+
      A[3][1] * B[1][0]+
      A[3][2] * B[2][0]+
      A[3][3] * B[3][0];


    C[0][1]=
      A[0][0] * B[0][1]+
      A[0][1] * B[1][1]+
      A[0][2] * B[2][1]+
      A[0][3] * B[3][1];

    C[1][1]=
      A[1][0] * B[0][1]+
      A[1][1] * B[1][1]+
      A[1][2] * B[2][1]+
      A[1][3] * B[3][1];

    C[2][1]=
      A[2][0] * B[0][1]+
      A[2][1] * B[1][1]+
      A[2][2] * B[2][1]+
      A[2][3] * B[3][1];

    C[3][1]=
      A[3][0] * B[0][1]+
      A[3][1] * B[1][1]+
      A[3][2] * B[2][1]+
      A[3][3] * B[3][1];


    C[0][2]=
      A[0][0] * B[0][2]+
      A[0][1] * B[1][2]+
      A[0][2] * B[2][2]+
      A[0][3] * B[3][2];

    C[1][2]=
      A[1][0] * B[0][2]+
      A[1][1] * B[1][2]+
      A[1][2] * B[2][2]+
      A[1][3] * B[3][2];

    C[2][2]=
      A[2][0] * B[0][2]+
      A[2][1] * B[1][2]+
      A[2][2] * B[2][2]+
      A[2][3] * B[3][2];

    C[3][2]=
      A[3][0] * B[0][2]+
      A[3][1] * B[1][2]+
      A[3][2] * B[2][2]+
      A[3][3] * B[3][2];


    C[0][3]=
      A[0][0] * B[0][3]+
      A[0][1] * B[1][3]+
      A[0][2] * B[2][3]+
      A[0][3] * B[3][3];

    C[1][3]=
      A[1][0] * B[0][3]+
      A[1][1] * B[1][3]+
      A[1][2] * B[2][3]+
      A[1][3] * B[3][3];

    C[2][3]=
      A[2][0] * B[0][3]+
      A[2][1] * B[1][3]+
      A[2][2] * B[2][3]+
      A[2][3] * B[3][3];

    C[3][3]=
      A[3][0] * B[0][3]+
      A[3][1] * B[1][3]+
      A[3][2] * B[2][3]+
      A[3][3] * B[3][3];
}


void SRM_2D_Transformation_Matrix
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float delta_x,
    SRM_Long_Float delta_y,
    SRM_Long_Float omega,
    SRM_Long_Float delta_scale
)
{
    SRM_Long_Float cox, sox;
    srm_sincos( -omega, sox, cox );

    memcpy(T,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));

    T[0][0]= cox;
    T[0][1]= sox;

    T[1][0]= -sox;
    T[1][1]= cox;

    T[0][2]=delta_x;
    T[1][2]=delta_y;
    {
        int i,j;
        for (i=0;i<2;i++)
            for (j=0;j<2;j++)
                T[i][j]*=(1.0+delta_scale*1.0e-6);
    }
}


/*
 * This function places in t a matrix for use with homogenous coordinates
 * that will perform the rotation and translation components of the
 * WGS 84 Conversion.  Scale is currently not used
 *
 *  Source is PDB: LTPxfer01.doc 11/18/2002
 */
void SRM_WGS84_Transformation_Matrix
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float delta_x,
    SRM_Long_Float delta_y,
    SRM_Long_Float delta_z,
    SRM_Long_Float omega_x,  /* omega_1 rot around x_axis*/
    SRM_Long_Float omega_y,  /* omega_2 rot around y_axis*/
    SRM_Long_Float omega_z,  /* omega_3 rot around z_axis*/
    SRM_Long_Float delta_scale
)
{
    SRM_Long_Float cox, coy, coz, sox, soy, soz;

    srm_sincos( -omega_x, sox, cox );
    srm_sincos( -omega_y, soy, coy );
    srm_sincos( -omega_z, soz, coz );

    SRM_Long_Float Tsr3[4][4],Tsr2[4][4],Tsr1[4][4], result1[4][4], result2[4][4];

  /*Initialize all of the matrixes involved to the 4x4 identity matrix*/

    memcpy(Tsr3,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(Tsr2,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(Tsr1,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(result1,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(result2,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));

    /*Initialize the upper left 3x3 to what we need it to be*/
    /* m1******************/
    /* These matrices are set up using the coordinate frame convention
     * rather than the position vector convention, which is why the
     * signs on the sine entries are flipped from what they would have
     * been for the position vector convention.
     */
    Tsr3[0][0]=  coz;  Tsr3[0][1]= soz;   Tsr3[0][2]= 0.0;

    Tsr3[1][0]= -soz;  Tsr3[1][1]= coz;   Tsr3[1][2]= 0.0;

    Tsr3[2][0]= 0.0;   Tsr3[2][1]= 0.0;   Tsr3[2][2]= 1.0;
    /* end m1 *************/

    /* m2 *****************/
    Tsr2[0][0]= coy;   Tsr2[0][1]= 0.0;   Tsr2[0][2]= -soy;

    Tsr2[1][0]= 0.0;   Tsr2[1][1]= 1.0;   Tsr2[1][2]= 0.0;

    Tsr2[2][0]= soy;   Tsr2[2][1]= 0.0;   Tsr2[2][2]= coy;
    /* end m2 *************/

    /* m3******************/

    Tsr1[0][0]= 1.0;   Tsr1[0][1]= 0.0;  Tsr1[0][2]= 0.0;

    Tsr1[1][0]= 0.0;   Tsr1[1][1]= cox;  Tsr1[1][2]= sox;

    Tsr1[2][0]= 0.0;   Tsr1[2][1]= -sox; Tsr1[2][2]= cox;
    /* end m3*/

    Impl_matrix_multiply4x4( Tsr2, Tsr1, result1);
    Impl_matrix_multiply4x4( Tsr3, result1, T);

    T[0][3]=delta_x;
    T[1][3]=delta_y;
    T[2][3]=delta_z;
    {
        int i,j;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                T[i][j]*=(1.0+delta_scale*1.0e-6);
    }
}


void SRM_WGS84_InverseTransformation_Matrix
(
    SRM_Long_Float T[4][4],
    SRM_Long_Float delta_x,
    SRM_Long_Float delta_y,
    SRM_Long_Float delta_z,
    SRM_Long_Float omega_x,  /* omega_1 rot around x_axis*/
    SRM_Long_Float omega_y,  /* omega_2 rot around y_axis*/
    SRM_Long_Float omega_z,  /* omega_3 rot around z_axis*/
    SRM_Long_Float delta_scale
)
{
    SRM_Long_Float cox, coy, coz, soz, soy, sox;

    srm_sincos( -omega_x, sox, cox );
    srm_sincos( -omega_y, soy, coy );
    srm_sincos( -omega_z, soz, coz );

    SRM_Long_Float Tsr3[4][4],Tsr2[4][4],Tsr1[4][4], result1[4][4], result2[4][4],
      delta_TR[4]={0.0,0.0,0.0,1.0},delta_RT[4];

    /*Initialize all of the matrixes involved to the 4x4 identity matrix*/

    memcpy(Tsr3,   Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(Tsr2,   Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(Tsr1,   Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(result1,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));
    memcpy(result2,Impl_Identity_Matrix4x4,sizeof(Impl_Identity_Matrix4x4));

  /*Initialize the upper left 3x3 to what we need it to be*/
  /* m1******************/
  /*$$$ The two instances
    of soz seem to have had their signs swapped in this matrix.
    No fix has been applied*/
    Tsr3[0][0]= coz;   Tsr3[0][1]= soz;   Tsr3[0][2]= 0.0;
    Tsr3[1][0]= -soz;  Tsr3[1][1]= coz;   Tsr3[1][2]= 0.0;
    Tsr3[2][0]= 0.0;   Tsr3[2][1]= 0.0;   Tsr3[2][2]= 1.0;
    /* end m1 *************/

    /* m2 *****************/
    Tsr2[0][0]= coy;   Tsr2[0][1]= 0.0;   Tsr2[0][2]= -soy;
    Tsr2[1][0]= 0.0;   Tsr2[1][1]= 1.0;   Tsr2[1][2]= 0.0;
    Tsr2[2][0]= soy;   Tsr2[2][1]= 0.0;   Tsr2[2][2]= coy;
    /* end m2 *************/

    /* m3******************/

    Tsr1[0][0]= 1.0;   Tsr1[0][1]= 0.0;  Tsr1[0][2]= 0.0;
    Tsr1[1][0]= 0.0;   Tsr1[1][1]= cox;  Tsr1[1][2]= sox;
    Tsr1[2][0]= 0.0;   Tsr1[2][1]= -sox; Tsr1[2][2]= cox;
    /* end m3*/

    Impl_matrix_multiply4x4(Tsr2, Tsr1, result1);
    Impl_matrix_multiply4x4(Tsr3, result1, result2);
    {
        for (int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                result2[i][j]*=1.0/(1.0+delta_scale*1.0e-6);
    }
    Impl_transpose(result2,T,4);

    delta_TR[0]=-delta_x;
    delta_TR[1]=-delta_y;
    delta_TR[2]=-delta_z;

    Impl_MultMatrixSubset(T,delta_TR,delta_RT,4,3);

    T[0][3]=delta_RT[0];
    T[1][3]=delta_RT[1];
    T[2][3]=delta_RT[2];
}

/*
 * FUNCTION: _mult_matrix_vector
 *
 *   This multiplies a matrix times a vector.  Though C matrices are stored in
 *   rows, this routine assumes that the vector stored as a row is actually a
 *   column vector and multiplies it in the normal fashion.
 */
Impl_Status
_mult_matrix_vector
(
    const double *A,
    const double *x,
          double *b,
    const int     rank
)
{
    Impl_Status status=IMPL_VALID;
    if (!(
          (A==0) |
          (x==0) |
          (b==0) |
          (rank <=0)))
    {
        int i,j;

        for(i=0;i<rank;++i)
        {
            b[i]=0;
            for(j=0;j<rank;++j)
            {
                b[i]+= (*(A+(i*rank)+j)) * x[j];
            }
        }
    }
    else /* Issue a Failure if we have 0 pointers or 0 rank*/
    {
        status=IMPL_INACTBLE;
    }
    return status;
}


/*
 * FUNCTION: _premult_matrix_vector
 *
 *   This multiplies a matrix times a vector.  Though C matrices are stored in
 *   rows, this routine assumes that the vector stored as a row is actually a
 *   column vector and multiplies it in the normal fashion
 *   This version of the routine computes xA=b
 */
Impl_Status
_premult_matrix_vector
(
    const double *A,
    const double *x,
          double *b,
    const int     rank
)
{
    Impl_Status status=IMPL_VALID;
    if (!(
        (A==0) |
        (x==0) |
        (b==0) |
        (rank <=0)))
    {
        int i,j;

        for(i=0;i<rank;++i)
        {
            b[i]=0;
            for(j=0;j<rank;++j)
            {
                b[i]+= x[j]* (*(A+(j*rank)+i)) ;
            }
        }
    }
    else  /* Issue a Failure if we have 0 pointers or 0 rank*/
    {
        status=IMPL_INACTBLE;
    }
    return status;
}


/*
 * FUNCTION: _mult_matrix_subset_vector
 *
 *   This routine allows us to multiply a matrix by a vector of a different
 *   rank. Such an operation is not generally applicable however it is of
 *   great utility using operators in homogenous coordinates because it allows
 *   the translational part of the matrix to be ignored.
 *   Places matrix on left column vector on right
 */
Impl_Status _mult_matrix_subset_vector
(
    const double *A,
    const double *x,
          double *b,
    const int     matrix_rank,
    const int     vector_rank
)
{
    Impl_Status status=IMPL_VALID;
    if (!(
          (A==0) |
          (x==0) |
          (b==0) |
          (matrix_rank <=0)|
          (vector_rank <=0)))
    {
        int i,j;

        for(i=0;i<vector_rank;++i)
        {
            b[i]=0;
            for(j=0;j<vector_rank;++j)
            {
                b[i]+= (*(A+(i*matrix_rank)+j)) * x[j];
            }
        }
    }
    else  /* Issue a Failure if we have 0 pointers or 0 rank*/
    {
        status=IMPL_INACTBLE;
    }
    return status;
}


void _print_matrix
(
    double *A,
    int     rank
)
{
    int i,j;
    for(i=0; i<rank; ++i)
    {
        for(j=0; j<rank; ++j)
            printf("%20.12f, ",*(A+(i*rank)+j));
        printf("\n");
    }
}


/* Function gee.
*/
SRM_Long_Float gee
(
    double h,
    double xlat,
    double a,
    double eps2
)
{
    SRM_Long_Float rn,g;
    register SRM_Long_Float s2 = srm_sin(xlat);
    s2 = s2 * s2;
    rn = a/sqrt(1.0-eps2*s2);
    g = (rn+h) / ((1.0-eps2)*rn+h);
    return (g);
}


SRM_Boolean
Impl_wellFormedCylindricalAngle
(
    SRM_Long_Float angle
)
{
    if ((angle >=0) && (angle < SRM_2_PI))
        return SRM_TRUE;
    else
        return SRM_FALSE;
}

SRM_Boolean
Impl_wellFormedAzimuth
(
    SRM_Long_Float azimuth
)
{
    if ((azimuth >= 0.0) && (azimuth < SRM_2_PI))
        return SRM_TRUE;
    else
        return SRM_FALSE;
}

SRM_Boolean
Impl_wellFormedLongitude
(
    SRM_Long_Float longitude
)
{
    if ((longitude > -SRM_PI) && (longitude <= SRM_PI))
        return SRM_TRUE;
    else
        return SRM_FALSE;
}

SRM_Boolean
Impl_wellFormedLatitude
(
    SRM_Long_Float latitude
)
{
    if ((latitude > -SRM_PI_DIV_2) && ( latitude < SRM_PI_DIV_2))
        return SRM_TRUE;
    else
        return SRM_FALSE;
}

SRM_Boolean
Impl_wellFormedRadius
(
    SRM_Long_Float radius
)
{
    if (radius > 0.0)
        return SRM_TRUE;
    else
        return SRM_FALSE;
}

SRM_Boolean
Impl_wellFormedScale
(
    SRM_Long_Float scale
)
{
    if (scale > 0.5 && scale <= 1.25)
        return SRM_TRUE;
    else
        return SRM_FALSE;
}


Impl_Status Impl_NormalizeDirection(SRM_Long_Float v[3])
{
    Impl_Status status = IMPL_VALID;
    SRM_Long_Float magnitude=sqrt(SQUARE(v[0])+SQUARE(v[1])+SQUARE(v[2]));
    if (magnitude*magnitude > EPSILON*EPSILON)
    {
        SRM_Long_Float scale=1.0/magnitude;

        v[0]*=scale;
        v[1]*=scale;
        v[2]*=scale;
    }
    else
    {
        v[0]=v[1]=v[2]=IMPL_NAN;
        status = IMPL_OBJSRC;
    }
    return status;
}


SRM_Long_Float Impl_compute_exact_chi
(
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cos_xki,
    SRM_Long_Float  sin_xki
)
{
    /*Used in testing to determine accuracy of chi approximations*/
    SRM_Long_Float b[4];
    SRM_Long_Float Eps2=e_constants->Eps2;
    SRM_Long_Float Eps4=(e_constants->Eps2*e_constants->Eps2);
    SRM_Long_Float sin_2_xki=sin_xki*sin_xki;
    b[0]=Eps2*(1.0+Eps2*(1.0+Eps2*(1.0+Eps2)));
    b[1]=-Eps4*(7.0+Eps2*(17.0+30.0*Eps2))/6.0;
    b[2]=Eps4*Eps2*(28.0/15.0+6223.0*Eps2/840.0);
    b[3]=-4279.0*(Eps4*Eps4)/1260.0;

    return (b[0]+sin_2_xki*(b[1]+sin_2_xki*(b[2]+sin_2_xki*b[3])))
      *cos_xki*sin_xki;
}

Impl_Status Impl_Init_chi_series
(
    const Impl_ORM_Data  *e_constants,
          SRM_Long_Float  b[4]
)
{
    Impl_Status status=IMPL_VALID;

    if (e_constants->Eps2 >= 0.0)
    {
        SRM_Long_Float Eps2=e_constants->Eps2;
        SRM_Long_Float Eps4=(e_constants->Eps2*e_constants->Eps2);
        b[0]=Eps2*(1.0+Eps2*(1.0+Eps2*(1.0+Eps2)));
        b[1]=-Eps4*(7.0+Eps2*(17.0+30.0*Eps2))/6.0;
        b[2]=Eps4*Eps2*(28.0/15.0+6223.0*Eps2/840.0);
        b[3]=-4279.0*(Eps4*Eps4)/1260.0;
    }
    else
    {
        b[0]=b[1]=b[2]=b[3]=IMPL_NAN;
        status=IMPL_INACTBLE;
    }
    return status;
}


Impl_Status Impl_Init_power_p_series
(
    const Impl_ORM_Data  *e_constants,
          SRM_Long_Float  cr1[5],
          SRM_Long_Float  cr2[5]
)
{
    Impl_Status status=IMPL_VALID;
    SRM_Long_Float AA1, AA2, AA3, AA4, AA5, AA6, AA7, AA8, AA9,
                   AB1, AB2, AB3, AB4, AB5, AB6, AB7, AB8, AB9,
                   BB1, BB2, BB3, BB4, BB5;

   /*
      AA1 - BB5 are magic numbers representing coefficients
      needed to compute a Taylor series approximation of
      POWERP
    */
    AA1= 0.100000000003490E+01;
    AA2=-0.643155723158021;
    AA3=-0.333332134894985;
    AA4=-0.241457540671514E-04;
    AA5= 0.143376648162652;
    AA6= 0.356844276587295;
    AA7=-0.333332875955149;
    AA8= 0.0;
    AA9= 0.0;

    BB1=AA1;
    BB2=e_constants->Eps2*AA2;
    BB3=e_constants->Eps2*(AA3+e_constants->Eps*(AA4+e_constants->Eps*AA5));
    BB4=e_constants->Eps2*AA6;
    BB5=e_constants->Eps2*(AA7+e_constants->Eps*(AA8+e_constants->Eps*AA9));

    /*Coefficients for POWER_P approximation with lat less than 35.5 degrees*/
    cr1[0]=BB3/BB5-.187E-11;
    cr1[1]=(BB2-BB4*BB3/BB5)/BB5;
    cr1[2]=(BB1-BB3/BB5)/BB5;
    cr1[3]=1.0/BB5;
    cr1[4]=BB4/BB5;

    AB1= 0.999999999957885;
    AB2=-0.115979311942142E+01;
    AB3=-0.333339671395063;
    AB4= 0.276473457331734E-03;
    AB5= 0.587786240368508;
    AB6=-0.159793128888088;
    AB7=-0.333333465982150;
    AB8= 0.746505041501704E-04;
    AB9=-0.701559218182283E-01;

    BB1=AB1;
    BB2=e_constants->Eps2*AB2;
    BB3=e_constants->Eps2*(AB3+e_constants->Eps*(AB4+e_constants->Eps*AB5));
    BB4=e_constants->Eps2*AB6;
    BB5=e_constants->Eps2*(AB7+e_constants->Eps*(AB8+e_constants->Eps*AB9));

    /*Coefficients for POWER_P approximation with lat greater than 35.5 degrees*/
    cr2[0]=BB3/BB5+.2689E-11;
    cr2[1]=(BB2-BB4*BB3/BB5)/BB5;
    cr2[2]=(BB1-BB3/BB5)/BB5;
    cr2[3]=1.0/BB5;
    cr2[4]=BB4/BB5;
    return status;
}

void Impl_ComputeArcLengthConstants
(
    const Impl_ORM_Data             *e_constants,
          Impl_Arc_Length_Constants *al
)
{
    /*n is the same in both the arclength and footpoint cases!*/
    al->n  = (e_constants->A-e_constants->B)/(e_constants->A+e_constants->B);
    al->P  = e_constants->A/(1.0+al->n);
    al->Pn = al->P*al->n;
    al->v  = SQUARE(al->n);
    al->Pv = al->P*al->v;
    al->u  = 23.3333333333333333*al->n;
    al->B0 = al->P+0.25*al->Pv;
    al->B2 = al->Pn*(-3.0+3.75*al->n-4.0*al->v);
    al->B4 = al->Pv*(-7.5 + al->u);
    al->B6 = -al->u*al->Pv;
}

SRM_Long_Float Impl_ArcLength
(
     Impl_Arc_Length_Constants *al,
     SRM_Long_Float             phi,
     SRM_Long_Float             sin_phi,
     SRM_Long_Float             cos_phi
)
{
    /*Arc length is often called Sa or S in SEDRIS related literature*/
    return (al->B0*phi)+(sin_phi*cos_phi)*(al->B2+SQUARE(sin_phi)*(al->B4+SQUARE(sin_phi)*al->B6));
}

/*
 * FUNCTION: Impl_ComputeFootpointConstants
 *
 *   Note that footpoint constants is interrelated with arclength constants,
 *   and that arclength constants must have been called with the same
 *   earth model and the results passed here for the initialization to work
 */
void Impl_ComputeFootpointConstants
(
    const Impl_ORM_Data             *e_constants,
          Impl_Arc_Length_Constants *al,
          Impl_Footpoint_Constants  *fp,
          SRM_Long_Float             central_scale
)
{
    fp->k0_inv=1.0/central_scale;
    fp->P1=al->n*(3.0+al->n*(5.25+7.75*(al->n)));
    /*Toms November 20, 2004 had 7.75 n^2 here instead of n which was
      an algebra error in the derivation*/
    fp->P2=-SQUARE(al->n)*(10.5+50.3333333333333333*al->n);
    fp->P3=50.3333333333333333*CUBE(al->n);
}

SRM_Long_Float Impl_Footpoint
(
    const Impl_ORM_Data             *e_constants,
          Impl_Arc_Length_Constants *al,
          Impl_Footpoint_Constants  *fp,
          SRM_Long_Float             mu
)
{
    SRM_Long_Float sin_mu, cos_mu;

    srm_sincos(mu, sin_mu, cos_mu);
    /*y is assumed to have been divided by the scale factor before if is pased to this routine*/
    return mu+sin_mu*cos_mu*(fp->P1+SQUARE(sin_mu)*(fp->P2+SQUARE(sin_mu)*(fp->P3)));
}

SRM_Long_Float Impl_compute_exact_footpoint
(
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  Ytm
)
{
    double e1,u,p2,p4,p6,p8, phi1;
    e1=(e_constants->A-e_constants->B)/(e_constants->A+e_constants->B);
    u=Ytm/(e_constants->A*(1-(SQUARE(e_constants->Eps)*(0.25+SQUARE(e_constants->Eps)*(3.0/64.0+5.0/256.0*SQUARE(e_constants->Eps))))));
    p2=e1*(3.0/2.0-27.0/32.0*SQUARE(e1));
    p4=SQUARE(e1)*(21.0/16.0-55.0/32.0*SQUARE(e1));
    p6=CUBE(e1)*151.0/96.0;
    p8=1097.0/512.0*SQUARE(e1)*SQUARE(e1);
    phi1=u+p2*srm_sin(2.0*u)+p4*srm_sin(4.0*u)+p6*srm_sin(6.0*u)+p8*srm_sin(8.0*u);

    return phi1;
}

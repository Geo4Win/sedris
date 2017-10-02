// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE       : SE_Matrix.cpp
//
// PROGRAMMERS: Eric Yee (SAIC), Howard Lu (SAIC), Bill Horan (SAIC)
//
// DESCRIPTION: Methods for SE_Matrix, a support class.  This implementation
//              of the matrix allows for variable sized matrix.  It allows
//              the user to do matrix arithematic on another matrix.  It
//              also has the LUP algorithm implemented for solving for
//              PA = LU, a necessary step in solving for the inverse matrix.
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_Matrix.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


SE_Matrix::SE_Matrix(SE_Integer_Unsigned row, SE_Integer_Unsigned column)
{
    if ((row < 1) || (column < 1))
    {
        fprintf(stderr, "SE_Matrix::SE_Matrix(): invalid matrix size!\n");
        columnSize = rowSize = matrixSize = 0;
        matrix     = NULL;
    }

    else
    {
        columnSize = row;
        rowSize    = column;
        matrixSize = columnSize * rowSize;

        // Allocate matrix of appropriate size and initialize to 0.
        matrix = new SE_Long_Float[matrixSize];
        memset(matrix, 0, matrixSize*sizeof(SE_Long_Float));
    }
}


SE_Matrix::SE_Matrix(const SE_Matrix& m)
{
    // Make a copy of the data.

    rowSize    = m.rowSize;
    columnSize = m.columnSize;
    matrixSize = m.matrixSize;
    matrix     = new SE_Long_Float[matrixSize];

    memcpy(matrix, m.matrix, sizeof(SE_Long_Float)*matrixSize);
}


SE_Matrix::~SE_Matrix()
{
    delete [] matrix;
    matrix = NULL;
}


SE_Long_Float&
SE_Matrix::operator()(SE_Integer_Unsigned rowIndex, SE_Integer_Unsigned columnIndex)
{
    if ((columnIndex >= rowSize) || (rowIndex >= columnSize))
    {
        fprintf(stderr, "SE_Matrix::operator(): Invalid index detected\n");
        rowIndex = 0;
        columnIndex = 0;
    }
    return matrix[rowIndex * rowSize + columnIndex];
}


SE_Matrix&
SE_Matrix::operator=(const SE_Matrix& m)
{
    if ((columnSize != m.columnSize) &&
        (rowSize != m.rowSize))
    {
        fprintf(stderr, "SE_Matrix::operator=(): "
                "Matrices do not the same size\n");
        return *this;
    }

    if (this != &m)
    {
        columnSize = m.columnSize;
        rowSize = m.rowSize;
        matrixSize = m.matrixSize;

        memcpy(matrix, m.matrix, sizeof(SE_Long_Float)*matrixSize);
    }
    return *this;
}


SE_Matrix
SE_Matrix::operator+(SE_Matrix& m)
{
    SE_Matrix sum(rowSize, columnSize);

    if((m.rowSize != rowSize) || (m.columnSize != columnSize))
    {
        fprintf(stderr, "SE_Matrix::operator+(): "
                "Matrices do not same size.  Cannot add.\n");
    }

    else
    {
        for (SE_Integer_Unsigned i = 0; i < rowSize; i++)
            for (SE_Integer_Unsigned j = 0; j < columnSize; j++)
                sum(i, j) =  (*this)(i, j) + m(i, j);
    }
    return sum;
}


void
SE_Matrix::setIdentity(void)
{
    if (columnSize != rowSize)
    {
        fprintf(stderr, "Matrix::setIdentity():"
                "Cannot set identity matrix.  This is not a square matrix\n");
        return;
    }

    // Set the identity matrix (all 0's except on the diagonal)
    memset(matrix, 0, sizeof(SE_Long_Float)*rowSize*rowSize);
    for (SE_Integer_Unsigned i=0; i < rowSize; i++)
        matrix[i * rowSize + i] = 1;
}


SE_Matrix
SE_Matrix::dot(SE_Matrix& m)
{
    SE_Matrix dotProduct(rowSize, m.columnSize);

    if (rowSize != m.columnSize)
        fprintf(stderr, "Matrix::dot:"
                "Matrices do not have the same size.  Aborted.\n");

    else
    {
        dotProduct.columnSize = columnSize;
        dotProduct.rowSize = m.rowSize;
        dotProduct.matrixSize = dotProduct.columnSize * dotProduct.rowSize;

        for (SE_Integer_Unsigned x = 0; x < columnSize; x++)
            for (SE_Integer_Unsigned y = 0; y < rowSize; y++)
                for (SE_Integer_Unsigned z = 0; z < m.rowSize; z++)
                {
                    dotProduct(x, z) += (*this)(x, y) * m(y, z);
                }
    }
    return dotProduct;
}


void
SE_Matrix::solve(SE_Long_Float b[], SE_Long_Float x[])
{
    SE_Matrix LU(rowSize, columnSize);
    SE_Integer *P = new SE_Integer[rowSize];

    if (columnSize != rowSize)
    {
        fprintf(stderr, "Matrix::solve(): not a square matrix. Can't solve\n");
        return;
    }

    LU = *this;
    if (LUP_Decomp(&LU, P) == SE_FALSE)
        fprintf(stderr, "SE_Matrix::solve():  unexpected error\n");
    else
        LUP_Solve(&LU, P, b, x);

    delete P;
}


void
SE_Matrix::print(void)
{
    for (SE_Integer_Unsigned x = 0; x < columnSize; x++)
    {
        for (SE_Integer_Unsigned y = 0; y < rowSize; y++)
            printf("%2.4f  ", matrix[x * rowSize + y]);
        printf("\n");
    }
    printf("\n");
}


SE_Boolean
SE_Matrix::LUP_Decomp(SE_Matrix *LU, SE_Integer P[])
{
    SE_Long_Float max, tmp;
    SE_Integer_Unsigned  i, j, k, k_prime;
    SE_Integer   tmp2;

    for (i = 0; i < columnSize; i++)
        P[i] = i;

    for (k = 0; k < rowSize - 1; k++)
    {
        max = 0.0f;
        for (i = k; i < rowSize; i++)
        {
            if (fabs(LU->matrix[i * rowSize + k]) > max)
            {
                max = fabs(LU->matrix[i * rowSize + k]);
                k_prime = i;
            }
        }

        if (max < 0.000001)
        {
            fprintf(stderr, "Singular matrix, can't decomp\n");
            return SE_FALSE;
        }

        tmp2 = P[k];
        P[k] = P[k_prime];
        P[k_prime] = tmp2;

        for (i = 0; i < rowSize; i++)
        {
            tmp = LU->matrix[k * rowSize + i];
            LU->matrix[k * rowSize + i] = LU->matrix[k_prime * rowSize + i];
            LU->matrix[k_prime * rowSize + i] = tmp;
        }

        for (i = k + 1; i < rowSize; i++)
        {
            LU->matrix[i * rowSize + k] =
              LU->matrix[i * rowSize + k] / LU->matrix[k * rowSize + k];
            for (j = k + 1; j < rowSize; j++)
              LU->matrix[i * rowSize + j] =
                LU->matrix[i * rowSize + j] - LU->matrix[i * rowSize + k] *
                  LU->matrix[k * rowSize + j];
        }
    }
    return SE_TRUE;
}


void
SE_Matrix::LUP_Solve
(
    SE_Matrix  *LU,
    SE_Integer    P[],
    SE_Long_Float  b[],
    SE_Long_Float  x[]
)
{
    SE_Integer_Unsigned   i, j;
    SE_Integer    i_down;
    SE_Long_Float *y = new SE_Long_Float[rowSize];
    SE_Long_Float sum;

    SE_Matrix *L = new SE_Matrix(LU->rowSize, LU->columnSize);
    SE_Matrix *U = new SE_Matrix(LU->rowSize, LU->columnSize);

    for (i = 0; i < rowSize; i++)
        for (j = 0; j < columnSize; j++)
        {
            if (i > j)  // lower triangular
                L->matrix[i * rowSize + j] = LU->matrix[i * rowSize + j];

            else if (i < j)  // upper triangular
                U->matrix[i * rowSize + j] = LU->matrix[i * rowSize + j];

            else // diagonal
            {
                L->matrix[i * rowSize + j] = 1.0;
                U->matrix[i * rowSize + j] = LU->matrix[i * rowSize + j];
            }
        }

    for (i = 0; i < rowSize; i++)
    {
        sum = 0;
        for (j = 0; j < i; j++)
            sum += L->matrix[i * rowSize + j] * y[j];
        y[i] = b[P[i]] - sum;
    }

    for (i_down = rowSize - 1; i_down >= 0; i_down--)
    {
        sum = 0;
        for (j = i_down + 1; j < rowSize; j++)
            sum += U->matrix[i_down * rowSize + j] * x[j];
        x[i_down] = (y[i_down] - sum) / U->matrix[i_down * rowSize + i_down];
    }

    delete y;
    delete L;
    delete U;
} // end SE_Matrix::LUP_Solve()

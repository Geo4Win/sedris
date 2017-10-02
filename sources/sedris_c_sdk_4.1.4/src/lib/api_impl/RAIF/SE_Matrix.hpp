// SEDRIS Level 0 Read API
//
// FILE:        SE_Matrix.hpp
//
// PROGRAMMERS: Eric Yee (SAIC), Howard Lu (SAIC), Bill Horan (SAIC)
//
// DESCRIPTION: class definition for SE_Matrix, a support class.
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

#ifndef _SE_MATRIX_HPP_INCLUDED
#define _SE_MATRIX_HPP_INCLUDED


/*
 * Allow C++ compilers to use this API without any problems
 */
extern "C"
{
#include "drm_stds.h"
}

#include "DataTypes.h"

class SE_Matrix
{
  public:
    SE_Matrix(SE_Integer_Unsigned rowLength, SE_Integer_Unsigned columnLength);
    SE_Matrix(const SE_Matrix&);  // copy constructor

    virtual ~SE_Matrix();

    /* overloading assignment operator. allows for assignment of matrices */
    SE_Matrix& operator=(const SE_Matrix&);

    /* allows for accessing individual elements within the matrix.  such as
     * m(0,0) = 1.25;   or
     * cout << m(3,2);
     */
    SE_Long_Float& operator()(SE_Integer_Unsigned rowIndex, SE_Integer_Unsigned columnIndex);

    /* overloading the addition operator, allows for A + B, where A and B
     * are matrices
     */
    SE_Matrix operator+(SE_Matrix&);

    /* sets the matrix as an identity matrix */
    void setIdentity(void);

    /* finds the dot product of 2 matrices A and B.  A is the object itself
     * while B is passed as a parameter.  The result will be returned
     */
    SE_Matrix dot(SE_Matrix&);

    /* With the equation Ax=b, we are given b, we know A (it's stored
     * as a matrix within the object, we are asked to solve for x
     */
    void solve(SE_Long_Float b[], SE_Long_Float x[]);

    void print(void);

  private:
    SE_Integer_Unsigned   columnSize;  /* number of elements in a column */
    SE_Integer_Unsigned   rowSize;     /* number of elements in a row */
    SE_Integer_Unsigned   matrixSize;  /* columnSize * rowSize */
    SE_Long_Float *matrix;  /* a pointer to an array of SE_Long_Float, the matrix */

    /*
     * LUP_Decomp() breaks down the matrix into an upper triangular (U) and
     * a lower triangular (L).  It returns both L and U in the same matrix (LU)
     * to conserve space.  P is an array to flag the pivoted identity matrix.
     * Both LU and P[] should have memory allocated to them already before
     * passing them into LUP_Decomp()
     */
    SE_Boolean LUP_Decomp(SE_Matrix *LU, SE_Integer P[]);

    /*
     * LUP_Solve() solves for x in the equation Ax=b where A is an nxn matrix,
     * x is an nx1 matrix and b is an 1xn matrix, when given the LUP Decomposed
     * matrix of A, P, b.  The answer will be stored in x.  x should already
     * have memory allocated to it before passing to LUP_Solve()
     */
    void LUP_Solve(SE_Matrix *LU, SE_Integer P[], SE_Long_Float b[], SE_Long_Float x[]);
};

#endif

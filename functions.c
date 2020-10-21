#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <stdlib.h>
#include "Const_Type.h"

const int SS_INF_ROOTS = -1;

/*!
\brief Check for correctness of the result of multiplying two double numbers.
\param [in] d1 is the first number.
\param [in] d2 second number.
\param [in] x (optional) the number by which to multiply the result of the multiplication.
\return res result of multiplication: res = x * d1 * d2.
*/

double checkDoubleOverflow (double d1, double d2, int x)
    {
        double res = x*d1*d2;

        assert( isfinite(res) );
        return res;
    }

/*!
\brief Checks that a floating point number is zero.
\param [in] d The number to check.
\return True / False if number is / is not equal to zero.
*/
Bool EqualZero (double d)
    { 
    if( abs(d) < DBL_EPSILON )
        return TRUE;
    else
        return FALSE;
    }
/*!
\brief Checks that floating point numbers are equal.
\param [in] d1 Number to check.
\param [in] d2 The number to check.
\return True / False if number is / is not equal to zero.
*/
Bool EqualDouble (double d1, double d2)
    {
    double d = d1 - d2;
    Bool res = EqualZero(d);

    return res;

    }

/*!
\brief Solve a linear equation ax = b.
\param [in] a coefficient a.
\param [in] b coefficient b.
\param [out] x1 Pointer to the first root.
\return Void
\note check for a! = 0 is enabled. When testing, the function sets 
*/
void LinSolve (double a, double b, double *x1)
    {   
        if ( EqualZero(a) )
            assert("Некорректно введены данные для функции LinSolve");

        *x1 = (-b)/a;
    }

/*!
\brief Check the correctness of the entered data.
\param [in] a coefficient a.
\param [in] b coefficient b.
\param [in] c coefficient c.
\param [out] x1 Pointer to the first root.
\param [out] x2 Pointer to the second root.
\return void function
\note Does not check data type out of bounds.
*/
void nCheckDouble (double a, double b, double c,
                    double *x1, double *x2)
    {
        assert ( isfinite(a) );
        assert ( isfinite(b) );
        assert ( isfinite(c) );

        assert ( x1 != x2 );
        assert ( x1 != NULL );
        assert ( x2 != NULL );
    }

/*!
\brief Solve a quadratic equation ax ^ 2 + bx + c = 0.
\param [in] a coefficient a.
\param [in] b coefficient b.
\param [in] c coefficient c.
\param [out] x1 Pointer to the first root.
\param [out] x2 Pointer to the second root.
\return Number of roots of the equation
\note in cases where the equation has no roots returns SS_INF_ROOTS
*/
int SquareSolve (double a, double b, double c,
                 double *x1, double *x2)
    {
        nCheckDouble (a, b, c, x1, x2);

        if ( EqualZero(a) )
        {
            if ( EqualZero(b) )
            {
                if ( EqualZero(c) )
                    return SS_INF_ROOTS;
                else // (c != 0)
                    return 0;
            }
            else // (b != 0)
            {
                if ( EqualZero(c) )
                {
                    *x1 = 0;
                    return 1;
                }
                else // (c != 0)
                {
                    *x1 = (-c)/b;
                    return 1;
                }
            }
        }
        else // (a != 0)
        {
            if ( EqualZero(b) )
            {
                if ( EqualZero(c) )
                {
                    *x1 = 0;
                    return 1;
                }
                else // (c != 0)
                {
                    if ( (-c)/a < 0)
                    {
                        return 0;
                    }
                    else // (-c)/a > 0
                    {
                        double D_special = (-c)/a;
                        *x1 = -sqrt ( D_special );
                        *x2 =  sqrt ( D_special );
                        return 2;
                    }
                }
            }
            else // (b != 0)
            {
                if ( EqualZero(c) )
                {
                    *x1 = 0;
                    LinSolve (a, b, x2);
                    return 2;
                }
                else // (c != 0)
                {
                    double D1, D2;
                    D1 = checkDoubleOverflow (b, b, 1);
                    D2 = checkDoubleOverflow (a, c, 4);
                    double D = D1 - D2;

                    if (D < 0)
                        return 0;
                    else if ( EqualZero (D) )
                    {
                        *x1 = (-b) / (2*a);
                        return 1;
                    }
                    else if ( D > 0 )
                    {
                        double sqr_D;
                        sqr_D = sqrt (D);

                        *x1 = ( (-b + sqr_D)/(2*a) );
                        *x2 = ( (-b - sqr_D)/(2*a) );

                        return 2;
                    }
                }
            }
        }
        return -1;
    }

/*!
\brief Sorts two variables. Puts a larger number in the first
\param [in] x1 - pointer to the first variable
\param [in] x2 - pointer to the first variable
\param [out] x1 - large variable
\param [out] x2 - smaller variable
\return void
*/
void Sort (double *x1, double *x2)
{
    double d_case;
    if( *x2 > *x1){
        d_case = *x2;
        *x2 = *x1;
        *x1 = d_case;
    }
}

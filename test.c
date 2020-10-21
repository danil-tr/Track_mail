#include "Functions.h"
#include <stdio.h>

void Unit_LinSolve (double a, double b, double correct_value, int line);
void Unit_SquareSolve_roots_exist (double a, double b, double c,
                        double correct_root1, double correct_root2, int correct_n, int line);
void Unit_SquareSolve_roots_no_exist (double a, double b, double c, int correct_n, int line);

void Unit_EqualZero (double d, Bool correct_equal, int line);     

/*!
\brief Tests the LinSolve function - solution ax + b = 0
\return Void
\note Calls Unit_LinSolve multiple times.
*/
void test_LinSolve()
{
    Unit_LinSolve ( 1, 1, -1, __LINE__ );
    Unit_LinSolve ( 2, -1, 0.5, __LINE__ );
    Unit_LinSolve ( 1, -1, 0.5, __LINE__ );
    Unit_LinSolve ( 100, 0, 0, __LINE__ );
}

/*!
\brief Tests the LinSolve function - solution ax + b = 0
\param [in] a coefficient a.
\param [in] b coefficient b.
\param [in] correct_value is the correct function value.
\param [in] line - line number with error.
\return Void
\note Validation checks are made before, a! = 0 whenever the function is called.
*/
void Unit_LinSolve (double a, double b, double correct_value, int line)
{
    double x = 0;
    LinSolve (a, b, &x);
    if ( EqualDouble(correct_value, x) )
    {
        printf ("Test on line %d ok\n", line); 
    }
    else 
    {
        printf ("Test failed on %d line: correct x = %lf, but function's result x = %lf.\n", line, correct_value, x);  
    }   
}

/*!
\brief Tests the SquareSolve function - solution ax ^ 2 + bx + c = 0
\return void
\note The function calls Unit_SquareSolve several times
*/
void test_SquareSolve()
{   
    Unit_SquareSolve_roots_exist (1, -5, 4, 4, 1, 2, __LINE__);
    Unit_SquareSolve_roots_exist (1, -5, 4, 1, 4, 2, __LINE__);
    Unit_SquareSolve_roots_exist (1, -8, 16, 4, 4, 1, __LINE__);
    Unit_SquareSolve_roots_exist (1, 0, -16, 4, -4, 2, __LINE__);
    Unit_SquareSolve_roots_exist (1, 0, -16, -4, 4, 2, __LINE__);
    Unit_SquareSolve_roots_exist (1, 4, 0, 0, -4, 2, __LINE__);
    Unit_SquareSolve_roots_exist (0, 4, 0, 0, 0, 1, __LINE__);
    Unit_SquareSolve_roots_no_exist (1, 3, 4, 0, __LINE__);
    Unit_SquareSolve_roots_no_exist (0, 0, 0, -1, __LINE__);
    Unit_SquareSolve_roots_no_exist (0, 0, 4, 0, __LINE__);
}

/*!
\brief Tests the SquareSolve function - solution ax ^ 2 + bx + c = 0 if there is at least one root.
\param [in] a coefficient a.
\param [in] b coefficient b.
\param [in] c coefficient c.
\param [in] correct_root1 is the first correct root.
\param [in] correct_root2 second correct root.
\param [in] correct_n number of roots.
\param [in] line - line number with error.
\return Void
\note The function passed the validation against the data entered earlier. If the roots are the same, then it is necessary to put in
the two variables are the same root.
*/
void Unit_SquareSolve_roots_exist (double a, double b, double c,
                        double correct_root1, double correct_root2, int correct_n, int line)
{
    double x1 = 0;
    double x2 = 0;

    int n = SquareSolve ( a, b, c, &x1, &x2 );

    if ( n != correct_n )
    {
        printf ("Test failed on %d line: correct number of roots %d, but function's result %d.\n", line, correct_n, n);
    }
    else // n == correct_n
    {
        if (n == 1) // случай одного корня
        {
            if ( EqualDouble( correct_root1, x1 ) )
                printf ("Test on line %d ok\n", line);

            else // корни не совпали
                printf ("Test failed on %d line: correct x =  %lf, but function's result %lf.\n", line, correct_root1, x1);
        }

        else // корня два
        {
            Sort (&x1, &x2);
            Sort (&correct_root1, &correct_root2);

            if ( EqualDouble( correct_root1, x1 ) && EqualDouble( correct_root2, x2 ) )
                printf ("Test on line %d ok\n", line);

            else
                printf ("Test failed on %d line: correct x =  {%lf, %lf}, but function's result x = {%lf, %lf}.\n",
                         line, correct_root1, correct_root2, x1, x2);    
        }
        
    }
   
}

/*!
\brief Tests the SquareSolve function - the solution ax ^ 2 + bx + c = 0, if there are no roots or it is any number.
\param [in] a coefficient a.
\param [in] b coefficient b.
\param [in] c coefficient c.
\param [in] correct_n number of roots.
\param [in] line - line number with error.
\return Void
\note The function passed the validation against the data entered earlier. If the roots are the same, then it is necessary to put in
the two variables are the same root.
*/
void Unit_SquareSolve_roots_no_exist (double a, double b, double c, int correct_n, int line)
{
    double x1, x2;
    int n = SquareSolve ( a, b, c, &x1, &x2 );

    if ( correct_n == n )
        printf ("Test on line %d ok\n", line);

    else
        printf ("Test failed on %d line: correct number of roots %d, but function's result %d.\n", line, correct_n, n);
}

void Test_EqualZero()
{
    Unit_EqualZero ( 0, TRUE, __LINE__ );
    Unit_EqualZero ( 2.00e-16, TRUE, __LINE__ );
}

void Unit_EqualZero (double d, Bool correct_equal, int line)
{
    Bool cur_equal = EqualZero(d);
    if ( cur_equal == correct_equal )
        printf ("Test on line %d ok\n", line);
    else 
        printf ("Test failed on %d line.\n", line);
}
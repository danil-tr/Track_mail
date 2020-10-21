#include <stdio.h>
#include <math.h>
#include "Functions.h"
#include "Test.h"



int main()
    {
    printf ("# Square equation solution. #\n");

    test_LinSolve();
    test_SquareSolve();
    Test_EqualZero();

    double a = NAN, b = NAN, c = NAN;
    double x1 = 0, x2 = 0;

    printf ("# Enter a, b, c coefficients #\n");
    scanf ("%lf %lf %lf", &a, &b, &c);
    int nRoots = SquareSolve (a, b, c, &x1, &x2);

    switch (nRoots)
    {
        case  0: printf ("The equation hasn't roots\n");
                break;
        case  1: printf ("One root is x = %lf\n", x1);
                break;
        case  2: printf ("Two roots are x1 = %lf, x2 = %lf\n", x1, x2);
                break;
        case -1: printf ("Roots are any numbers\n");
                break;
        default: printf ("main(): error: nRoots = %d\n", nRoots);
                return 1;
    }

    return 0;
}
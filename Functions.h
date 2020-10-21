#ifndef Functions_h
#define Functions_h

#include "Const_Type.h"

double checkDoubleOverflow(double d1, double d2, int x);

void nCheckDouble (double a, double b, double c,
                    double *x1, double *x2);

Bool EqualZero (double d);

Bool EqualDouble (double d1, double d2);

void LinSolve (double a, double b, double *x1);

int SquareSolve (double a, double b, double c,
                 double *x1, double *x2);

void Sort (double *x1, double *x2); 
#endif
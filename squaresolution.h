#ifndef SQUARESOLUTION_H_INCLUDED
#define SQUARESOLUTION_H_INCLUDED

enum number_of_roots{
    INF = - 1,
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    THREE = 3
};

extern const float consr;

/** *****************************************************************************************************
 * Text
*/

int equality (double a, double b);

/** *****************************************************************************************************
 * Text
*/

void linear_solution (double b, double c, double *x1, int *n);

/** *****************************************************************************************************
 * Text
*/

void square_solution (double a, double b, double c, double *x1, double *x2, int *n);

/** *****************************************************************************************************
 * Text
*/

char test_square_solution ();

#endif

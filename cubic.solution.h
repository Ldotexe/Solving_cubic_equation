#ifndef CUBIC_SOLUTION_H_INCLUDED
#define CUBIC_SOLUTION_H_INCLUDED

enum number_of_roots{
    INF = - 1,
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    THREE = 3
};

enum sq_solution_error{
    SQ_SOLUTION_OK,
    SQ_SOLUTION_NO_POINTER,
    SQ_SOLUTION_NAN
};

extern const char* sq_solution_value[]; // array of strings with names of errors

extern const double pi; // pi

extern const float consr; // constant for comparison

/** *****************************************************************************************************
 * @param a first number to compare
 * @param b second number to compare
 * Compares two numbers of type double with some accuracy (default accuracy is constant consr)
*/

int equality (double a, double b, double epsilon = consr);

/** *****************************************************************************************************
 * @brief solves the linear equation
 * @param a first coefficient in the liner equation with form a * x + b = 0
 * @param b second coefficient in the liner equation with form a * x + b = 0
 * @param x1 solution of equation
 * @param n number of roots
 *
 * solves the linear equation with possible results of number of roots as infinite, zero or one
 * does not change the value of x1 if the number of roots isn't one
 * infinite number of roots shows up as -1
 * returns the code of error, if there is any with the parameters
*/

sq_solution_error linear_solution (double b, double c, double *x1, int *n);

/** *****************************************************************************************************
 * @brief solves the quadratic equation
 * @param a first coefficient in the square equation with form a * x^2 + b * x + c = 0
 * @param b second coefficient in the liner equation with form a * x^2 + b * x + c = 0
 * @param c third coefficient in the liner equation with form a * x^2 + b * x + c = 0
 * @param x1 first solution of equation
 * @param x2 second solution of equation
 * @param n number of roots
 * solves the square equation with possible results of number of roots as infinite, zero, one or two
 * if a = 0, calls the linear_solution program
 * does not change the values of x1 and x2 if the number of roots is less then index of solution
 * puts in x1 and x2 only real values
 * returns the code of error, if there is any with the parameters
*/

sq_solution_error square_solution (double a, double b, double c, double *x1, double *x2, int *n);

/** *****************************************************************************************************
 * @brief solves the cubic equation
 * @param a first coefficient in the square equation with form a * x^3 + b * x^2 + c * x + d = 0
 * @param b second coefficient in the liner equation with form a * x^3 + b * x^2 + c * x + d = 0
 * @param c third coefficient in the liner equation with form a * x^3 + b * x^2 + c * x + d = 0
 * @param d fourth coefficient in the liner equation with form a * x^3 + b * x^2 + c * x + d = 0
 * @param x1 first solution of equation
 * @param x2 second solution of equation
 * @param x3 third solution of equation
 * @param n number of roots
 * solves the square equation with possible results of number of roots as infinite, zero, one, two three
 * if a = 0, calls the square_solution program
 * does not change the values of x1, x2 and x3 if the number of roots is less then index of solution
 * puts in x1, x2, x3 only real values
 * returns the code of error, if there is any with the parameters
*/

sq_solution_error cubic_solution (double a, double b, double c, double d, double *x1, double *x2, double *x3, int *n);

#endif // CUBIC_SOLUTION_H_INCLUDED

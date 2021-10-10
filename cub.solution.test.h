#ifndef CUB_SOLUTION_TEST_H_INCLUDED
#define CUB_SOLUTION_TEST_H_INCLUDED

extern const double rude_consr; // rude constant for comparison because of accuracy of program solving cubic equation

struct cubic_test{
    double a;
    double b;
    double c;
    double d;
    int resultn;
    double resultx1;
    double resultx2;
    double resultx3;
};

/** *****************************************************************************************************
 * Test for program, solving cubic equation using struct cubic_test
 * Runs program, solving the equation and compares to supposed value
*/

char test_cube_solution();

#endif // CUB_SOLUTION_TEST_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include "squaresolution.h"

struct square_test{
    double a;
    double b;
    double c;
    int resultn;
    double resultx1;
    double resultx2;
};

char test_square_solution(){
    square_test test[] = {
        {     1,           2,           1,  ONE,           -1,               0},
        {     0,           0,         7.0, ZERO,            0,               0},
        {     0,           0,           0,  INF,            0,               0},
        {    48,         987,          -5,  TWO, -20.56756461,  0.005064608701},
        {48.567,    987.9999,       -0.87,  TWO, -20.34390975, 0.0008805287779},
        {467.32, 320170.2784, 54838765.28,  TWO, -342.5630517,    -342.5569483},
        {4.6732, 32.01702784, 54.83876528,  ONE, -3.425630517,               0}
    };
    double x1 = NULL, x2 = NULL;
    int n = NULL;
    for (int i = 0; i < sizeof(test)/sizeof(square_test); i++){
        x1 = NULL; x2 = NULL;
        square_solution(test[i].a, test[i].b, test[i].c, &x1, &x2, &n);
        if (!equality(x1, test[i].resultx1) || !equality(x2 - test[i].resultx2, 0) || n != test[i].resultn){
            printf("Error on test number %d\n", i + 1);
            printf("Inputs: %f %f %f\n", test[i].a, test[i].b, test[i].c);
            printf("Results(roots and number of roots): %f %f %d\n", x1, x2, n);
            printf("Expected(roots and number of roots): %f %f %d\n", test[i].resultx1, test[i].resultx2, test[i].resultn);
            return 0;
        }
    }
    return -1;
}

char test();

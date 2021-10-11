#include <stdio.h>
#include <math.h>
#include "cubic.solution.h"
#include "cub.solution.test.h"

const double rude_consr = 0.01;

char test_cube_solution(){
    cubic_test test[] = {
        {   0,          1,           2,           1,   ONE,           -1,               0,               0},
        {   0,          0,           0,         7.0,  ZERO,            0,               0,               0},
        {   0,          0,           0,           0,   INF,            0,               0,               0},
        {   0,         48,         987,          -5,   TWO, -20.56756461,  0.005064608701,               0},
        {   0,     48.567,    987.9999,       -0.87,   TWO, -20.34390975, 0.0008805287779,               0},
        {   0,     467.32, 320170.2784, 54838765.28,   TWO, -342.5630517,    -342.5569483,               0},
        {   0,     4.6732, 32.01702784, 54.83876528,   ONE, -3.425630517,               0,               0},
        {   1,         -2,          -1,           2, THREE,            2,              -1,               1},
        { 100,        500,       -1000,          -9, THREE,  1.538378777,    -6.529418845, -0.008959931742},
        {-666, 954849.894,  987112.895,   -541258.7, THREE,  1434.741199,    -1.429032621,    0.3963829347},
        {7.82,       1.89,    3.456891,         369,   ONE, -3.654289178,               0,               0},
        {6.66,   -41.5584, -526.776696, 3480.380136,   TWO,           -9,            7.62,               0}
    };
    double x1 = 0, x2 = 0, x3 = 0;
    int n = 0;
    for (int i = 0; i < sizeof(test)/sizeof(cubic_test); i++){
        x1 = NULL; x2 = NULL; x3 = NULL;
        cubic_solution(test[i].a, test[i].b, test[i].c, test[i].d, &x1, &x2, &x3, &n);

        if (!equality(x1, test[i].resultx1, rude_consr) || !equality(x2, test[i].resultx2, rude_consr) || !equality(x3, test[i].resultx3, rude_consr) || n != test[i].resultn){
            printf("Error on test number %d\n", i + 1);
            printf("Inputs: %f %f %f %f\n", test[i].a, test[i].b, test[i].c, test[i].d);
            printf("Results(roots and number of roots): %f %f %f %d\n", x1, x2, x3, n);
            printf("Expected(roots and number of roots): %f %f %f %d\n", test[i].resultx1, test[i].resultx2, test[i].resultx3, test[i].resultn);
            return -1;
        }
    }
    return 0;
}

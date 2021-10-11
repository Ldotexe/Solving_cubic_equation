#include <iostream>
#include <stdio.h>
#include "cubic.solution.h"
#include "cub.solution.test.h"
#include "math.h"

sq_solution_error solving_equations (int *n, double *x1, double *x2, double *x3);
sq_solution_error print_result_eq (int n, double x1, double x2, double x3);

int main()
{
    double x1 = NAN, x2 = NAN, x3 = NAN;
    int n = 0;
    solving_equations(&n, &x1, &x2, &x3);
    return 0;
}

sq_solution_error solving_equations (int *n, double *x1, double *x2, double *x3){
    if (n == nullptr || x1 == nullptr || x2 == nullptr || x3 == nullptr){
        return SQ_SOLUTION_NO_POINTER;
    }
    int mode = 0;
    while(mode + 1){
        printf("Please, enter mode of working in range from 1 to 3 or end program with -1\n"
               "Or you can test square solution program with 0 mode\n\n");
        if (!scanf("%d", &mode)){
            break;
        }
        switch (mode){
        case -1:
            printf("Thank you for using my program!\n"
                   "Good bye!\n");
            break;
        case 0:
            printf("Tests passed %s\n\n", test_cube_solution() == 0 ? "Yes" : "No") ;
            break;
        case 1:{
            double a = NAN, b = NAN;
            if (scanf("%lg %lg", &a, &b) == 2 && !isnan(a) && !isnan(b)){
                linear_solution(a, b, x1, n);
                print_result_eq (*n, *x1, *x2, *x3);
            }
            else{
                printf("Program end\n");
                return SQ_SOLUTION_OK;
            }
            break;
        }
        case 2:{
            double a = NAN, b = NAN, c = NAN;
            if (scanf("%lg %lg %lg", &a, &b, &c) && !isnan(a) && !isnan(b) && !isnan(c)){
                square_solution(a, b, c, x1, x2, n);
                print_result_eq (*n, *x1, *x2, *x3);
            }
            else{
                printf("Program end\n");
                return SQ_SOLUTION_OK;
            }
            break;
        }
        case 3:{
            double a = NAN, b = NAN, c = NAN, d = NAN;
            if(scanf("%lg %lg %lg %lg", &a, &b, &c, &d) && !isnan(a) && !isnan(b) && !isnan(c) && !isnan(d)){
                cubic_solution(a, b, c, d, x1, x2, x3, n);
                print_result_eq (*n, *x1, *x2, *x3);
            }
            else{
                printf("Program end\n");
                return SQ_SOLUTION_OK;
            }
            break;
        }
        default:
            printf("Oops! Wrong mode!\n"
                   "Please, try again, mode can be in range from 1 to 3\n\n");
        }
    }
    printf("Program end\n");
    return SQ_SOLUTION_OK;
}


sq_solution_error print_result_eq (int n, double x1, double x2, double x3){
    if (isnan(n)){
        return SQ_SOLUTION_NAN;
    }
    switch(n){
        case -1:
            printf("Infinite number of roots\n");
            break;
        case 0:
            printf("Number of real roots: %d\n", n);
            break;
        case 1:
            printf("Number of real roots: %d\n%g\n", n, x1);
            break;
        case 2:
            printf("Number of real roots: %d\n%g %g\n", n, x1, x2);
            break;
        case 3:
            printf("Number of real roots: %d\n%g %g %g\n", n, x1, x2, x3);
            break;
        default:
            printf("Oops! Please, make sure that number of real roots is in range from 0 to 3\n");
    }
    return SQ_SOLUTION_OK;
}

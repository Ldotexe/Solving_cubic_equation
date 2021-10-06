#include <iostream>
#include <stdio.h>
#include "squaresolution.h"
//#include "sq.solution.test.h"

void solving_equations (int *n, double *x1, double *x2, double *x3);
void print_result_eq (int n, double x1, double x2, double x3);

int main()
{
    double x1 = NULL, x2 = NULL, x3 = NULL;
    int n = NULL;
    test_square_solution();
    solving_equations(&n, &x1, &x2, &x3);
    return 0;
}

void solving_equations (int *n, double *x1, double *x2, double *x3){
    int mode = NULL;
    while(mode + 1){
        printf("Please, enter mode of working in range from 1 to 3 or end program with -1\n");
        if (!scanf("%d", &mode)){
            break;
        }
        switch (mode){
        case -1:
            printf("Thank you for using my program!\n"
                   "Good bye!\n");
            break;
        case 1:{
            double a = NULL, b = NULL;
            scanf("%lg %lg", &a, &b);
            linear_solution(a, b, x1, n);
            print_result_eq (*n, *x1, *x2, *x3);
            break;
        }
        case 2:{
            double a = 0, b = NULL, c = NULL;
            scanf("%lg %lg %lg", &a, &b, &c);
            square_solution(a, b, c, x1, x2, n);
            print_result_eq (*n, *x1, *x2, *x3);
            break;
        }
        case 3:{
            printf("Oops! We can't solve equations with 3 roots yet\n");
            break;
        }
        default:
            printf("Oops! Wrong mode!\n"
                   "Please, try again, mode can be in range from 1 to 3\n");
        }
    }
}


void print_result_eq (int n, double x1, double x2, double x3){
    switch(n){
        case -1:
            printf("Infinite number of roots\n");
            break;
        case 0:
            printf("Number of roots: %d\n", n);
            break;
        case 1:
            printf("Number of roots: %d\n%g\n", n, x1);
            break;
        case 2:
            printf("Number of roots: %d\n%g %g\n", n, x1, x2);
            break;
        case 3:
            printf("Number of roots: %d\n%g %g %g\n", n, x1, x2, x3);
            break;
        default:
            printf("Number of roots: Oops! Please, make sure that number of roots is in range from 0 to 3\n");
    }
}

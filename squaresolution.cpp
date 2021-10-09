#include <math.h>
#include <stdio.h>
#include "squaresolution.h"

const double pi = 3.1416;//3.1415926535897932384626433832795028;

const float consr = 0.0001;

const char* sq_solution_value[] = {
    "SQ_SOLUTION_OK",
    "SQ_SOLUTION_NO_POINTER",
    "SQ_SOLUTION_NAN"
};

int equality (double a, double b, double epsilon){
    if (fabs(a-b) <= epsilon){
        return 1;
    }
    else{
        return 0;
    }
}

sq_solution_error linear_solution (double b, double c, double *x1, int *n){
    // a * x + b = 0
    if (x1 == nullptr || n == nullptr){
        return SQ_SOLUTION_NO_POINTER;
    }
    if (isnan(b) || isnan(c)){
        return SQ_SOLUTION_NAN;
    }
    if (!equality(b, 0))
    {
        *x1 = -c/b;
        *n = 1;
    }
    else
    {
        if (!equality(c, 0))
            *n = 0;
        else
            *n = INF;
    }
    return SQ_SOLUTION_OK;
}

sq_solution_error square_solution (double a, double b, double c, double *x1, double *x2, int *n)
{
    // a * x^2 + b * x + c = 0
    if (x1 == nullptr || x2 == nullptr || n == nullptr){
        return SQ_SOLUTION_NO_POINTER;
    }
    if (isnan(a) || isnan(b) || isnan(c)){
        return SQ_SOLUTION_NAN;
    }
    if (equality(a, 0))
    {
        linear_solution(b, c, x1, n);
    }
    else
    {
        double d = b*b-4*a*c;
        if (d < 0)
            *n = 0;
        else
        {
            if (equality(d, 0))
            {
                *x1 =- b/(2*a);
                *n = 1;
            }
            else
            {
                float sd = sqrt(d);
                *n = 2;
                *x1 = (-b-sd)/(2*a);
                *x2 = (-b+sd)/(2*a);
            }
        }
    }
    return SQ_SOLUTION_OK;
}

sq_solution_error cubic_solution (double a, double b, double c, double d, double *x1, double *x2, double *x3, int *n){
    // a * x^3 + b * x^2 + c * x + d = 0
    if (x1 == nullptr || x2 == nullptr || x3 == nullptr || n == nullptr){
        return SQ_SOLUTION_NO_POINTER;
    }
    if (isnan(a) || isnan(b)  || isnan(c) || isnan(d)){
        return SQ_SOLUTION_NAN;
    }
    if (equality(a, 0)){
        square_solution(b, c, d, x1, x2, n);
    }
    else{
        // x = y - b / 3 * a
        double p = (3 * a * c - b * b) / (3 * a * a);
        double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
        // y^3 + p * y + q = 0
        double s = (q * q / 4) + (p * p * p / 27); // s - Discriminant
        if (s < 0){
            double F = pi / 2;
            if (q < 0){
                F = atan(sqrt(-s) / (- q / 2));
            }
            if (q > 0){
                F = atan(sqrt(-s) / (- q / 2)) + pi;
            }
            *n = 3;
            *x1 = 2 * sqrt(-p / 3) * cos(F / 3) - b / (3 * a);
            *x2 = 2 * sqrt(-p / 3) * cos(F / 3 + 2 * pi / 3) - b / (3 * a);
            *x3 = 2 * sqrt(-p / 3) * cos(F / 3 + 4 * pi / 3) - b / (3 * a);
            return SQ_SOLUTION_OK;
        }
        if (equality(s, 0)){
            *n = 2;
            if (- q / 2 < 0){
                *x1 = - 2 * pow(q / 2, 0.333) - b / (3 * a);
                *x2 = pow(q / 2, 0.333) - b / (3 * a);
            }
            else{
                *x1 = 2 * pow(-q / 2, 0.333) - b / (3 * a);
                *x2 = - pow(-q / 2, 0.333) - b / (3 * a);
            }
            return SQ_SOLUTION_OK;
        }
        if (s > 0){
            *n = 1;
            if (-q / 2 - sqrt(s) > 0){
                *x1 = pow((-q / 2) + sqrt(s), 0.333) + pow((-q / 2) - sqrt(s), 0.333) - b / (3 * a);
            }
            else{
                if ((-q / 2) + sqrt(s) < 0){
                    *x1 = - pow((q / 2) - sqrt(s), 0.333) - pow((q / 2) + sqrt(s), 0.333) - b / (3 * a);
                }
                else{
                    *x1 = pow((-q / 2) + sqrt(s), 0.333) - pow((q / 2) + sqrt(s), 0.333) - b / (3 * a);
                }
            }
            return SQ_SOLUTION_OK;
        }
    }
    return SQ_SOLUTION_OK;
}

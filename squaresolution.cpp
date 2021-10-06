#include <math.h>
#include <stdio.h>
#include "squaresolution.h"

const float consr = 0.0001;

int equality (double a, double b)
{
    if (fabs(a-b) <= consr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void linear_solution (double b, double c, double *x1, int *n){
    if (!equality(b, 0))
    {
        *x1 = -c/b;
        *n = 1;
    }
    else
    {
        if(!equality(c, 0))
            *n = 0;
        else
            *n = INF;
    }
}

void square_solution (double a, double b, double c, double *x1, double *x2, int *n)
{
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
}

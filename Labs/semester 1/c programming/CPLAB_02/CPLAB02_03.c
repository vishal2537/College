/*Write a C program to input two numbers from user and find their power using
pow() function. */


#include <stdio.h>
#include <math.h>

int main()
{
    double base, expo, power;

    printf("Enter base: ");

    scanf("%lf", &base);

    printf("Enter exponent: ");

    scanf("%lf", &expo);

    power = pow(base, expo);

    printf("%.2lf ^ %.2lf = %.2lf", base, expo, power);

    return 0;
}

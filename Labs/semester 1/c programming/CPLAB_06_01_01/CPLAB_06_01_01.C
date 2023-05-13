#include <stdio.h>
double pow(double a, int b);
int main()
{
    double a, power;
    int b;
    printf("Enter base: ");
    scanf("%lf", &a);
    printf("Enter exponent: ");
    scanf("%d", &b);
    power = pow(a, b);
    printf("%.2lf ^ %d = %f", a, b, power);
    return 0;
}

double pow(double a, int b)
{
    if(b == 0)
        return 1;
     else if(b > 0)
        return a * pow(a, b - 1);
    else
        return 1 / pow(a, -b);
}
















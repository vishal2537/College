#include <stdio.h>
// struct Numbers{int number1,number3,number2;};

typedef struct complex
{
    int real;
    int imaginary;
} complex;

complex add(complex a, complex b)
{
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}
int main()
{
    complex a, b, final;
    a.real = 1;
    b.real = 2;
    a.imaginary = 4;
    b.imaginary = 1;
    final = add(a, b);
    printf("sum of %d + %di and %d + %di is %d + %di", a.real, a.imaginary, b.real, b.imaginary, final.real, final.imaginary);

    return 0;
}
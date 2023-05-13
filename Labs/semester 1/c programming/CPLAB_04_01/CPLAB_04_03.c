/*Accept a decimal number from the user. Print the equivalent binary number. Continue accepting numbers until the user gives a value of 0, signifying that he has finished entering inputs.*/

#include <stdio.h>

int main()
{
    int number, n, remainder, a = 0, b = 1;

    printf("Enter a number :");
    scanf("%d", &number);
    n = number;

    while (n > 0)
    {
        remainder = n % 2;
        a += remainder * b;
        b *= 10;
        n /= 2;
    }

    printf("BINARY NUMBER =  %d", a);
    return 0;
}

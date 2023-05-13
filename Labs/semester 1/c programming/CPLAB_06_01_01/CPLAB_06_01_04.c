
#include <stdio.h>
#include <math.h>
int reverse(int n);
int Palin(int n);
int main()
{
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    if(Palin(n) == 1)
    {
        printf("%d is palindrome number.\n", n);
    }
    else
    {
        printf("%d is NOT palindrome number.\n", n);
    }

    return 0;
}
int Palin(int n)
{
    if(n == reverse(n))
    {
        return 1;
    }
    else
    return 0;
}
int reverse(int n)
{
    int digit = (int)log10(n);
    if(n == 0)
        return 0;
    else
    return ((n%10 * pow(10, digit)) + reverse(n/10));
}

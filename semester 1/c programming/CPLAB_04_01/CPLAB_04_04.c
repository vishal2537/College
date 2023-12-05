/*Print all strong numbers between 1 to 500. Strong number
is a special number whose sum of factorial of digits is
equal to the original number.*/

#include <stdio.h>

int main()
{
    int i, j, a, b ;
    long long fact, sum;
    printf("All Strong numbers between 1 to 500 are:\n");

    for(i=1; i<=500; i++)
    {
        a = i;
        sum = 0;
        while(a > 0)
        {
            fact = 1;
            b = a % 10;
            for( j=1; j<=b; j++)
            {
                fact = fact * j;
            }

            sum += fact;
            a /= 10;
        }
        if(sum == i)
        {
            printf("%d, ", i);
        }
    }

    return 0;
}

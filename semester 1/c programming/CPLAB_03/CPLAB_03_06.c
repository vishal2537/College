//find whether a given number is prime or not.


#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);

    int a=0;

    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        a++;
    }
    if(a!=0)
    {
        printf("Not a prime number\n");
    }
    else
    {
        printf("Prime number\n");
    }

    return 0;
}

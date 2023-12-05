//find whether a given integer is odd or even using ternary operator

#include<stdio.h>
int main()
{
    int n;

    printf("ENTER AN INTEGER\n");
    scanf("%d",&n);

    n%2 == 0 ? printf("EVEN NUMBER\n"): printf("ODD NUMBER\n");


    return 0;


}

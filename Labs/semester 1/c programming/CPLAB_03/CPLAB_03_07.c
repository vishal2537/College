// find the factorial of a given number.

#include<stdio.h>

int main()
{
    int n, i=1,factorial=1;
    printf("ENTER ANY NUMBER;");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        factorial *=i;
    }
     printf("THE VALUE OF FACTORIAL %d IS %d" ,n,factorial );
     return 0;
}




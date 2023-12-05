#include<stdio.h>
int main()

{
    int n;
    printf("How many number you want to enter ? \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        printf(" Enter number is : %d \n",arr[i]);

    }
    return 0;
}


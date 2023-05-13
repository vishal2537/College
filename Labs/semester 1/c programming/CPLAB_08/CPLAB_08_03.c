#include<stdio.h>
int main()
{
    int n;
    printf("enter the number you want to enter : \n");
    scanf("%d",&n);
    int arr[n];
    scanf("%d",&arr[0]);
    int max=arr[0];
    int min=arr[0];
    for(int i=1; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
        if(min>arr[i])
        {
            min=arr[i];
        }
    }
    printf("max = %d \n",max);
    printf("min = %d \n",min);
    return 0;
}

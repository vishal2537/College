#include <stdio.h>
int main()
{
    int n;
    printf("enter the number of element : \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum = sum + arr[i];

    }
    printf(" total sum = %d ", sum);
    return 0;

}

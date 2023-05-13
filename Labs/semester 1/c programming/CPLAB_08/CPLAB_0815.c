

#include <stdio.h>

void rotate(int arr[], int n)
{
   int x = arr[n-1], i;
   for (i = n-1; i > 0; i--)
      arr[i] = arr[i-1];
   arr[0] = x;
}

int main()
{
    int k;
    printf("no. of element : ");
    scanf("%d",&k);
    int arr[k]; //= {1, 2, 3, 4, 5};
    for(int i=0 ;i< k ;i++)
        {
        scanf("%d",&arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    rotate(arr, n);

    printf("Rotated array is ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

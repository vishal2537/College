#include<stdio.h>
 
int main()
{
  int arr[5] = { 1, 2, 3, 4, 5 };
  int *ptr = arr;
 
  for (int i = 0; i < 5; ++i)
        printf("%d\n", *(ptr + i));
        
  return 0;
}

// #include<stdio.h>
// int main()
// {
//   int *a;
//   int n;
//   printf("enter size of the array");
//   scanf("%d",&n);
//   int x[n];
//   printf("enter numbers to store in array");
//   for(int i=0;i<n;i++)
//   scanf("%d",&x[i]);
//   a=&x[0];
//   printf("entered numbers are");
//   for(int j=0;j<n;j++)
//   printf("%d\n",*(a++));
//   return 0;

// }

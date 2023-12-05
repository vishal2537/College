#include <stdio.h>
int main()
{
    int A[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    int(*p)[4][5];
    p = &A;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("*(*p + %d) = %d\n", 5 * i + j, *(*(*p + i) + j));
        }
    }
    return 0;
}



// #include<stdio.h>
// int main()
// {
//   printf("enter the value of m and n");
//   int m,n;
//   scanf("%d%d",&m,&n);
//   int *p[m][n];
//   int x[m][n];
//   for(int i=0;i<m;i++)
//   {
//     for(int j=0;j<n;j++)
//     {
//     scanf("%d",&(x[i][j]));
//     }
//   }
//   for(int k=0;k<m;k++)
//   {
//     for(int l=0;l<n;l++)
//     {
//     p[k][l]=&x[k][l];
//     }
//   }
//   for(int k=0;k<m;k++)
//   {
//     for(int l=0;l<n;l++)
//     {
//      printf("%d",*(p++));
//     }
//     printf("\n");
//   }
//   return 0;
// }









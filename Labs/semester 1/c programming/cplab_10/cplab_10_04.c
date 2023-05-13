

#include <stdio.h>
int main(){
    int A[4][5] = {{1,2,3,4,5},
                   {6,7,8,9,10},
                   {11,12,13,14,15},
                   {16,17,18,19,20}};
    int *p,i;
    p=&A[0][0];    
    for (i = 0; i < 20; i++){
        printf("address:%d = %d\n", p+i, *p+i);}    
    return 0;    
}













































// #include <stdio.h>
//     int main()
//     {
//         int *a;
//         printf("enter the value of m and n");
//         int m, n;
//         scanf("%d%d", &m, &n);
//         int x[m][n];
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 scanf("%d", &x[i][j]);
//             }
//         }
//         a = &(x[0][0]);
//         for (int k = 0; k < m; k++)
//         {
//             for (int l = 0; l < n; l++)
//                 printf("%d", *(a++));
//             printf("\n");
//         }
//         return 0;
//     }




// #include <stdio.h>
// int main()
// {

//     int A[4][5];
//     int i, j;
//     for (i = 0; i < 4; i++)
//     {
//         for (j = 0; j < 5; j++)
//         {
//             printf("Enter value for A[%d][%d]:", i, j);
//             scanf("%d", &A[i][j]);
//         }
//     }


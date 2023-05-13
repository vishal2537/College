
#include<stdio.h>
int main(){
    int A[4][5] = {{1,2,3,4,5},
                   {6,7,8,9,10},
                   {11,12,13,14,15},
                   {16,17,18,19,20}};
    int (*p)[4][5];
    p=&A;
    int i,j;
    for (i = 0; i < 20; i++){
        printf("address:%d = %d\n", *(*p)+i, *(*(*p)+i));}
    printf("in column major format,\n address:%d = %d\n address:%d = %d\n address:%d = %d\n address:%d = %d\n address:%d = %d\n address:%d = %d\n address:%d = %d\n address:%d = %d\netc.\n Therefore our multidimensional array is in row major format",*(*p), 1,*(*p)+1, 6,*(*p)+2, 11,*(*p)+3, 16,*(*p)+4, 2,*(*p)+5, 7,*(*p)+6, 12,*(*p)+7, 17);
    return 0;    
}

// #include<stdio.h>
// int main()
// {
//   int *a;
//   printf("enter the value of m and n");
//   int m,n;
//   scanf("%d%d",&m,&n);
//   int x[m][n];
//   for(int i=0;i<m;i++)
//   {
//     for(int j=0;j<n;j++)
//     {
//     scanf("%d",&x[i][j]);
//     }
//   }
//   a=&x[0][0];
//   for(int i=0;i<m*n;i++)
//   printf("%x\n",a++);
//   return 0;
// }
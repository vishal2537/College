#include<stdio.h>

int maxHandshake(int n);
int main()
{
     int n;
     printf("ENTER NUMBER OF STUDENT : ");
     scanf("%d" ,&n );
     printf("MAXIMUM NUBER OF HAND SHAKE = %d " , maxHandshake(n));
     return 0;
}

int maxHandshake(int n)
{
  return (n * (n - 1))/ 2;
}


#include<stdio.h>
int main()
{
  int n;
  printf("Enter the number of rows: ");
  scanf("%d",&n);
  for(int row=1; row<=n; row++)
  {
    int a=1;

    for(int j=1; j<=10-row; j++)
    printf(" ");

    for(int i=1; i<=row; i++)
    {
      printf("%d ",a);
      a = a * (row-i)/i;
    }
    printf("\n");
  }
  return 0;
}

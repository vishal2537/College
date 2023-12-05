#include<stdio.h>
int large(int a, int b);

int main()
{

    int a,b;
    printf("ENTER THE TWO NUMBER:");
    scanf("%d %d" ,&a ,&b);

    printf(" LARGEST NUMBER BETWEEN %d and %d is %d\n ", a ,b, large(a,b) );
    return 0;

}
int large(int a, int b )
{
    if(a>b){
   return a;}
   else
    return b;

}

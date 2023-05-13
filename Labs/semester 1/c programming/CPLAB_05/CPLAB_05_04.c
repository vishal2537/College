#include<stdio.h>
int countDigit(int n);
int main()
{
    int a , b;
    printf("PROGRAM TO COUNT THE NUMBER OF DIGIT\n");

    printf("ENTER THE NUMBER:\n");
    scanf("%d",&a);
    b=countDigit(a);
    printf("NUMBER OF DIGIT IN %d IS %d " ,a , b);

}
int countDigit(int n)
{
   static int x=0;
    if(n>0)
    {
        x=x+1;
        return countDigit(n/10);

    }
    else
        return x;
}


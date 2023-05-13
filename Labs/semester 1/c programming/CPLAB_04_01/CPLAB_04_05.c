/*Print the first 10 terms of the geometric progression
starting from n1 with common ratio d. The geometric
progression must be printed with each term separated by
a comma and a blank space. Print the sum of the above
geometric progression.*/


#include<stdio.h>
#include <math.h>
int main(){

    int a,r,sum=0;
    printf(" First term and Common Ratio\n");
    scanf("%d %d",&a,&r);
    for (int  i = 0; i < 10; i++)
    {
       long long x=a*pow(r,i);
       sum +=x;
       printf("%d , ",x);
    }
    printf("\n");

    printf("The Sum is %d",sum);


    return 0;

}

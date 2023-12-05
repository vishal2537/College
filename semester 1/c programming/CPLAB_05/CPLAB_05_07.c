#include<stdio.h>
#include<math.h>

double series(int,int);
double factorial(int);

int main()
{
    int x,n;
    double y;

    printf("\nPlease enter a value for x and an odd value for n\n");
    scanf("%d%d",&x,&n);
    if(n%2==0)
    {
        n=n-1;
    }
    y=series(x,n);
    printf("For the values you've entered, the value of the series is:\n%lf",y);
}

double series(int s, int t)
{
    int i,sign=1; double r=0.0,fact,exec;
    for(i=1;i<=t;i+=2)
    {
        exec=sign*(pow(s,i)/factorial(i));
        r+=exec;
        sign*=-1;
    }
    return r;
}

double factorial(int p)
{
    double f=1;
    while(p>0)
    {
        f*=p;
        p--;
    }
    return f;
}

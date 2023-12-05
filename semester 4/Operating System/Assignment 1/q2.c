#include<stdio.h>

void pr_params(int n , char **params) {
    char *temp = *params;
    while(*temp != '\0')
    {
        printf("%c",*temp);
        temp ++;
    }
    printf("\n");

}

int main()
{
    int n;
    scanf("%d\n",&n);
    char s[n][100];
    for(int i=0;i<n;i++)
    {
        scanf("%[^\n]%*c",s[i]);
    }

    // for(int i=0;i<n;i++)
    // {
    //     printf("%s\n",s[i]);
    // }

    char params[n*500] ;
    int i=0;
    for(int iterator =0 ;iterator<n;iterator++)
    {
        char *temp= s[iterator];
        while(*temp != '\0')
        {   
            params[i] = *temp;
            i++;
            // printf("%s",*temp);
            temp = temp + 1;
        }
        params[i++] = '\n';
    }
    params[i]= '\0';
    char *temp1 = params;
    pr_params(n,&temp1);
    return 0;
}

#include<stdio.h>
#include<string.h>
void main()
{
    int i=0,j=0,k=0,a,minIndex=0,maxIndex=0,max=0,min=0;
    char str1[100]={0},substr[100][100]={0},c;
    printf("Enter a sentence\n");
    gets(str1);
    while(str1[k]!='\0')//for splitting sentence
    {
        j=0;
        while(str1[k]!=' '&&str1[k]!='\0')
        {
            substr[i][j]=str1[k];
            k++;
            j++;
        }
        substr[i][j]='\0';
        i++;
        if(str1[k]!='\0')
        {
            k++;
        }
    }
    int len=i;
    max=strlen(substr[0]);
    min=strlen(substr[0]);

    for(i=0;i<len;i++)
    {
       a=strlen(substr[i]);
       if(a>max)
        {
            max=a;
            maxIndex=i;
        }
        if(a<min)
        {
            min=a;
            minIndex=i;
        }
    }
  printf("Largest Word is %s \nSmallest word is %s\n",substr[maxIndex],substr[minIndex]);

}














    //After splitting getting length of string and finding its index having max length and index having min length

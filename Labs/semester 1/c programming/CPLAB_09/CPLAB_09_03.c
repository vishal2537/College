#include <stdio.h>
#include <string.h>

int main()
{

printf("\nENTER THE SENTENCE FOR YOU WANT TO FIND THE NUMBER OF WORD : \n");
    char sent[10000];
    gets(sent);
    int word = 1;
    
    for (int i = 0; i < strlen(sent)-1; i++)
    {
        if (sent[i]==' '||sent[i]=='\n'||sent[i]=='\t')
        {
           word++; 
        }
        
    }
    printf("total word = %d",word);
    
        return 0;
}
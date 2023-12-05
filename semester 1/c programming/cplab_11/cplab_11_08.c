#include <stdio.h>
int main()
{
    char str[100];

    printf("\nPLEASE ENTER FULL STOP AT THE LAST SENTENCE : \n");
    scanf("%[^.]",str);

    int words=0,nl=0,chr=0; 
    for(int i=0;str[i]!='\0';i++)
     { 
         if(str[i] == ' ')
         { 
              words++;
         }
         else if(str[i] == '\n')
         {
             nl++;
              words++;}
         else if(str[i] != ' ' && str[i] != '\n'){
         chr++;
         }
     }
    if(chr > 0)
    {
        words++;
        nl++;
    }
     printf("Total number of words : %d\n",words);
     printf("Total number of lines : %d\n",nl);
     printf("Total number of characters : %d\n",chr);
    return 0;
}

















































// scanf("%[^~]",&str);//scanf formatting 
    // gets(str);

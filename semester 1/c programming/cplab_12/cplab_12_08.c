#include<stdio.h>
int main()
{
      int ch;
      FILE *f1,*f2;
      f1=fopen("a.txt","r");
      f2=fopen("backup_a.txt","w");   
      if(f1==NULL||f2==NULL)
            printf("File is blank.");
      else
            while((ch=fgetc(f1))!=EOF)
            {
                  fputc(ch,f2);
            }
      printf("File copied.");
      return 0;
}
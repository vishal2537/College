#include <stdio.h>
#include <string.h>
 
int main()
{
  	char str[100], ch;
  	int i, len, j;
 
  	printf("\nEnter String :  ");
  	gets(str);
  	
  	printf("\nEnter the Character that you want to Remove :  ");
  	scanf("%c", &ch);
  	
	len = strlen(str);
	   	
  	for(i = 0; i < len; i++)
	{
		if(str[i] == ch)
		{
			for(j = i; j < len; j++)
			{
				str[j] = str[j + 1];
			}
			len--;
			i--;	
		} 
	}	
	printf("\nFinal String = %s ", str);
	
  	return 0;
}
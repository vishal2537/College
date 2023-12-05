#include <stdio.h>
#include <string.h>
 
int main ()
{
	char str[100], word[100], twoD[10][30];
	int i = 0, j = 0, k = 0, len1 = 0, len2 = 0;
 
	printf ("Enter the string:\n");
	gets (str);
 
	printf ("Enter the word to be removed:\n");
	gets (word);
 
	// convert the string into 2D array
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			twoD[k][j] = '\0';
			k ++;
			j = 0;
		}
		else
		{
			twoD[k][j] = str[i];
			j ++;
		}
	}
 
	twoD[k][j] = '\0';
 
	j = 0;
	for (i = 0; i < k + 1; i++)
	{
		if (strcmp(twoD[i], word) == 0)
		{
			twoD[i][j] = '\0';
		}
	}
 
	j = 0;
 
	for (i = 0; i < k + 1; i++)
	{
		if (twoD[i][j] == '\0')
			continue;
		else
			printf ("%s ", twoD[i]);
	}
 
	printf ("\n");
 
	return 0;
}
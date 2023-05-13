#include <stdio.h>


// print the string 
void pr_params(char **params)
{
  for (int i = 0; params[i] != NULL; i++)
  {
    printf("s%d %s\n", i + 1, params[i]);
  }
}

int main()
{
  char s1[100], s2[100], s3[100];

  printf("Enter the first string: ");
  scanf("%[^\n]%*c", s1);

  printf("Enter the second string: ");
  scanf("%[^\n]%*c", s2);

  printf("Enter the third string: ");
  scanf("%[^\n]%*c", s3);

  char *params[500] = {s1, s2, s3, NULL};

  // for (int i = 0; i < 4; i++)
  // {
  //   printf("%s",params[i]);
  // }
   
  pr_params(params);

  return 0;
}
#include<stdio.h>
void check(char x,int y,float z)
{
printf("%c\n%d\n%f\n",x,y,z);
}
int main()
{
  int a=5;
  char b='a';
  float c=2.5f;
  check(b,a,c);
  return 0;
}

/*Write a C program to find the sum of digits of a 3 digit number.
Example:Input : 123
Output : 1+2+3=6
Input: 274
Output: 2+7+4= 13*/

#include<stdio.h>

int main(){
int a;
printf("Enter a 3 digit number: ");
scanf("%d",&a);
int b1=a/100;
int c=a-b1*100;
int c1=c/10;
int d1=c-c1*10;
int sum=b1+c1+d1;
printf("The sum of the digits is: %d",sum);
return 0;
}

/*Write a C program to create calculator that performs basic arithmetic operations (add, subtract, multiply and divide) using switch case and functions. The calculator should input two numbers and an operator from user. It should
perform operation according to the operator entered and must take input in given format.*/

#include<stdio.h>
int main()
 {
    char ch;
    float a, b ;
    printf("CALCULATOR FOR {+ - * /}\n");
    printf("ENTER OPERATION:");
    scanf("%c",&ch);
    printf("ENTER THE TWO NUMBER:\n");
    scanf("%f %f " , &a, &b);

    switch(ch){
    case'+':
    printf("%.2f + %.2f = %.2f" , a,b, a+b);
    break;

    case'-':
    printf("%.2f - %.2f = %.2f" , a,b, a-b);
    break;

    case'*':
    printf("%.2f * %.2f = %.2f" , a,b, a*b);
    break;

    case'/':
    printf("%.2f / %.2f = %.2f" , a , b, a/b);
    break;

    default:
        printf("error");
    }
 return 0;
}


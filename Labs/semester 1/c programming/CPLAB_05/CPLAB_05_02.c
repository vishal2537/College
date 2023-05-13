#include<stdio.h>
#include<stdlib.h>
void fun();

int main()
{
    fun();
    printf("NOT FROM THE FUNCTION \n");
    fun();
    return 0;
}

void fun()
{

    printf("FROM THE FUNCTION !\n");

}

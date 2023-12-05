#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    char *Q;
}*q;


void create(char arr[]){

    q =(struct stack *)malloc(sizeof(struct stack));
    q->size=1000;
    q->top=-1;
    q->Q=(char *)malloc(1000*sizeof(char));
    int i=0;
    while (arr[i])
    {
        q->top++;
        q->Q[i]=arr[i];
        i++;
    }
}

void display(){
    
    int i=q->top;

    while (i!=-1)
    {
        q->top++;
        printf("%c",q->Q[i]);
        i--;
    }
    printf("\n");

}

int main(){

    char str[1000];
    printf("Enter the string\n");
    scanf("%s",str);

    printf("The initial string is : \n");
    printf("%s",str);

    create(str);
    printf("The final string is : \n");
            
    display();
    
    return 0;
}
#include<stdio.h>
void fun(int *p){
    int q=20;
    p=&q;

}
int main(){
    int a=10;
    int *p=&a;
    fun(p);
    printf("%d",*p);
    
    
return 0;
}

#include <stdio.h>
struct customer
{
    char name[30];
    int accno;
    int balance;
} cust[10];
int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("\nEnter name: ");
        scanf("%s", cust[i].name);
        cust[i].accno = i;
    }
    for (i = 0; i < 10; i++)
    {
        printf("\nEnter balance ");
        scanf("%d", &cust[i].balance);
    }

    printf("\n Customers with balance less than 200:");
    for (i = 0; i < 10; i++)
    {
        if (cust[i].balance < 200)
        {
            printf("\nName:%s, Balance:%d: ", cust[i].name, cust[i].balance);
        }
    }
    printf("\n Customers with balance more than 1000,now incremented by 100:");
    for (i = 0; i < 10; i++)
    {
        if (cust[i].balance > 1000)
        {
            cust[i].balance += 100;
            printf("\nName:%s, Balance:%d: ", cust[i].name, cust[i].balance);
        }
    }
    return 0;
}

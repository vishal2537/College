#include <stdio.h>
void count(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    printf("number of 1 is : %d \n", count);
}

int main()
{
    int n;
    printf("ENTER NUMBER : ");
    scanf("%d", &n);
    count(n);

    return 0;
}
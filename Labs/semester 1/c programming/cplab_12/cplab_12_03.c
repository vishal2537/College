#include <stdio.h>

int main()
{
    int n, m;
    printf("ENTER A 32 BIT NUMBER : ");
    scanf("%d", &n);
    printf("\nENTER THE BIT NUMBER i.e.(0-31) : ");
    scanf("%d", &m);
    n = n >> m;
    if (n & 1 == 1)
        printf("%d th bit is set \n", n);
    else
        printf("%d th bit not set\n", n);

    return 0;
}
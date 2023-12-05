#include <stdio.h>

int main()
{
    int num, n, m;
    printf("Enter any number: ");
    scanf("%d", &num);

    printf("Enter nth bit to toggle (0-31): ");
    scanf("%d", &n);
    m = num ^ (1 << n);

    printf("Before toggling %d bit: %d (in decimal)\n", n, num);
    printf("After toggling %d bit: %d (in decimal)\n", n, m);
}
 
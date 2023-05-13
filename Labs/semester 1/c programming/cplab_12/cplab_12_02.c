#include <stdio.h>

int main()
{
    int n;
    printf("\nProgram to check even or odd \n\n");
    printf("Enter number: ");
    scanf("%d", &n);

    if(n & 1)
    {
        printf("%d is odd.", n);
    }
    else
    {
        printf("%d is even.", n);
    }

    return 0;
}

#include <stdio.h>
void displayNumbers(int num[0][2]);

int main()
{
    int num[2][2];
    printf("ENTER 4  NUMBERS :\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &num[i][j]);
    // passing multi diumensiional array to afunction
    displayNumbers(num);
    return 0;
}

void displayNumbers(int num[0][2])
{
    
    printf("display:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            printf("%d\n", num[i][j]);
}

// Find a special element in a given 2-D array, whose value is least in a given row and highest in the corresponding column.

#include <stdio.h>

int main()
{
    int i, j, rows, columns, a[100][100];

    printf("\nEnter Number of rows and columns  :  ");
    scanf("%d %d", &i, &j);

    printf("\nEnter the Matrix Elements Row wise : \n");
    for (rows = 0; rows < i; rows++)
    {
        for (columns = 0; columns < j; columns++)
        {
            scanf("%d", &a[rows][columns]);
        }
    }

    int min = a[0][0];
    int max = a[0][0];

    for (rows = 0; rows < i; rows++)
    {
        for (columns = 0; columns < j; columns++)
        {
            if (a[rows][columns] < min)
            {
                min = a[rows][columns];
            }
            if (a[rows][columns] > max)
            {
                max = a[rows][columns];
            }
        }
    }
    printf("\nMinimum number is %d ", min);
    printf("\nMaximum number is %d ", max);

    return 0;
}

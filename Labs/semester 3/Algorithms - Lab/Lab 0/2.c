#include <stdio.h>
#include <stdlib.h>

int L[30], n;

int check_position(int r, int c)
{
    int i;
    for (i = 1; i <= r - 1; i++)
    {
        if (L[i] == c)
        {
            return 0;
        }
        else
        {
            if (abs(L[i] - c) == abs(i - r))
                return 0;
        }
    }
    return 1;
}

void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++n);

    for (i = 1; i <= n; ++i)
        printf("\t%d", i);

    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j) // for nxn board
        {
            if (L[i] == j)
                printf("\tQ"); // queen at i,j position
            else
                printf("\t-"); // empty slot
        }
    }
}

void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            L[row] = column; // no conflicts so place queen
            if (row == n)    // dead end
                print(n);    // printing the board configuration
            else             // try queen with next position
                queen(row + 1, n);
        }
    }
}

int main()
{
    int n, i, j;
    printf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &L[i]);
    }

    return 0;
}
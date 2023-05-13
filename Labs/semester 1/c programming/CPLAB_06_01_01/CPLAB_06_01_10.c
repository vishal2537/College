#include<stdio.h>
int prime(int num);
void main()
{
	int i, j;
	int num = 2, rows;
	printf("Enter the number :");
	scanf("%d", &rows);

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j <= i; j++)
		{
			while (!prime(num))
			{
				num++;
			}
			printf("%d  ", num++);
		}
		printf("\n");
	}
}

int prime(int num)
{
	int i, x;
	for (i = 2; i < num; i++)
	{
		if (num % i != 0)
			x = 1;
		else
		{
			x = 0;
			break;
		}
	}
	if (x == 1 || num == 2)
		return 1;
	else
		return 0;
}

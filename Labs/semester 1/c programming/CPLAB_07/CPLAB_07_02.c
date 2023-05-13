
#include<stdio.h>

int main()
{
 	int i, j, rows, columns, arr[10][10], temp;

 	printf("Enter Number of rows and columns  :  ");
 	scanf("%d %d", &i, &j);

 	printf("Matrix Elements :\n");
 	for(rows = 0; rows < i; rows++)
  	{
   		for(columns = 0;columns < j;columns++)
    	{
      		scanf("%d", &arr[rows][columns]);
    	}
  	}

  	if(rows == columns)
  	{
  		for(rows = 0; rows < i; rows++)
  		{
  			temp = arr[rows][rows];
  			arr[rows][rows] = arr[rows][i - rows - 1];
  			arr[rows][i - rows - 1] = temp;
	   	}

 		printf("\n New Matrix : \n");
 		for(rows = 0; rows < j; rows++)
  		{
   			for(columns = 0; columns < i; columns++)
    		{
      			printf("%d \t ", arr[rows][columns]);
    		}
    		printf("\n");
  		}
  	}
  	return 0;
}

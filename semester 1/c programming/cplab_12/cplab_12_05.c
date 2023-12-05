#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 1000

int main()
{
    char data[DATA_SIZE];
    FILE * fPtr;
    fPtr = fopen("file1.txt", "w");
    if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter contents to store in file : \n");
    fgets(data, DATA_SIZE, stdin);

    fputs(data, fPtr);
    fclose(fPtr);
    printf("File created and saved successfully. :) \n");
    return 0;
}
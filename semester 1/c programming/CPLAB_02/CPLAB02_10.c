//Write a C program to check whether an alphabet is vowel or consonant using if else

#include <stdio.h>

int main()
{
    char ch;

    printf("Please Enter an alphabet: \n");
    scanf(" %c", &ch);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
		ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')  {
		printf("\n %c is a VOWEL.", ch);
	}
    else {
    	printf("\n %c is a CONSONANT.", ch);
	}
    return 0;
}

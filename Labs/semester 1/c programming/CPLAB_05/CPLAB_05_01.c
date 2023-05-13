#include<stdio.h>
int main()
{
    char ch;
    printf("PROGRAM TO CHECK VOwEL AND CONSONANT USING SWITCH CASE \n");
    printf("ENTER ANY ALPHABET:");
    scanf("%c",&ch);

    switch(ch)
    {
    case 'a':
        case 'e':
            case 'i':
                case 'o':
                    case 'u':
                        case 'A':
                            case 'E':
                                case 'O':
                                    case 'I':
                                        case 'U':

                                            printf(" GIVEN ALPHABET VOWEL");
                                            break;

                                        default:
                                            printf("GIVEN ALPHABET IS CONSONENT");

    }

    return 0;

}

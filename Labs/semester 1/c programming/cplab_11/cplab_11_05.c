#include <stdio.h>
struct student
{
    char Name[50];
    int roll;
    int age;
} s[5], a;

int main()
{

    int i;
    for (i = 0; i < 5; ++i)
    {
        printf("\nEnter roll number :");
        scanf("%d", &s[i].roll);

        printf("\nEnter age :");
        scanf("%d", &s[i].age);

        printf("\nEnter name: ");
        scanf("%s", &s[i].Name);
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (s[j].roll < s[j+1].roll)
                a = s[j];
            s[j] = s[j + 1];
            s[j + 1] = a;
        }
    }

    printf("Student details :\n");
    for (i = 0; i < 5; ++i)
    {
        printf("\nRoll number : %d\n", s[i].roll);
        printf("Age : %d\n", s[i].age);
        printf("Name : ");
        puts(s[i].Name);
        printf("\n");
    }
    return 0;
}

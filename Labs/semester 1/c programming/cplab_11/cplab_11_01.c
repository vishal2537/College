#include <stdio.h>
struct student {
    char Name[50];
    int roll;
    int age;
} s[5];

int main() {

    int i;
    for (i = 0; i < 5; ++i) {
        printf("\nEnter roll number :");
        scanf("%d", &s[i].roll);

        printf("\nEnter age :");
        scanf("%d", &s[i].age);

        printf("\nEnter name: ");
        scanf("%s", &s[i].Name);
    }
    
    printf("Student details :\n");
    for (i = 0; i < 5; ++i) {
        printf("\nRoll number : %d\n", s[i].roll);
        printf("Age : %d",s[i].age);
        printf("Name : ");
        puts(s[i].Name);

        printf("\n");
    }
    return 0;
}

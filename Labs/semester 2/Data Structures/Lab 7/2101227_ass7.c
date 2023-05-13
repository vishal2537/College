#include <stdio.h>
#include <stdlib.h>
#define N 10000

// declaration of variable
struct student
{
    int roll_number;
    int marks[3];
};

// swapping of structure
void swap(struct student *stud, int i, int j)
{
    struct student temp = stud[i];
    stud[i] = stud[j];
    stud[j] = temp;
}

// quick sort
int partition(struct student *stud, int low, int high)
{
    int pivot = stud[high].roll_number;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (stud[j].roll_number <= pivot)
        {
            i++;
            swap(stud, i, j);
        }
    }
    swap(stud, i + 1, high);
    return i + 1;
}
void quick_sort(struct student *stud, int low, int high)
{
    if (low >= high)
        return;
    int p = partition(stud, low, high);
    quick_sort(stud, low, p - 1);
    quick_sort(stud, p + 1, high);
}

// insertion_sort
void insertion_sort(struct student *stud, int s)
{
    for (int i = 1; i < s; i++)
    {
        int j = i - 1;
        while (j >= 0 && stud[i].roll_number < stud[j].roll_number)
        {
            swap(stud, i--, j--);
        }
    }
}

// display data
void print_record(struct student *stud, int low, int high, int no_of_subject)
{
    for (int i = low; i <= high; i++)
    {
        if (no_of_subject == 2)
            printf("PDE ");
        printf("%d ", stud[i].roll_number);

        if (stud[i].roll_number / N == 10)
            printf("Gryffindor ");

        else if (stud[i].roll_number / N == 11)
            printf("Hufflepuff ");

        else if (stud[i].roll_number / N == 12)
            printf("Ravenclaw ");

        else
            printf("Slytherine ");
        for (int j = 0; j < no_of_subject; j++)
        {
            printf("%d(00%d) ", stud[i].marks[j], j + 1);
        }
        printf("\n");
    }
    printf("\n");
}

// storing data
void studentrecord(struct student *stud, int rollno, int marks[], int *s, int no_of_subject)
{
    stud[*s].roll_number = rollno;
    for (int i = 0; i < no_of_subject; i++)
    {
        stud[*s].marks[i] = marks[i];
    }
    (*s)++;
}

// for inserting data
void insert(struct student *stud, struct student *PDE, int *s, int *indx)
{
    int n = 3;
    while (n--)
    {
        int roll_number, marks[3];
        printf("\nenter roll number : ");
        scanf("%d", &roll_number);
        while (roll_number / N < 10 || roll_number / N > 13)
        {
            printf("!! invalid format of roll number , please try again !! \n");
            scanf("%d", &roll_number);
        }
        printf("\nenter marks : ");
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &marks[j]);
        }
        if (roll_number / N >= 10 && roll_number / N <= 13)
        {
            studentrecord(&(*stud), roll_number, marks, &(*s), 3);
            if (marks[0] < 40 && marks[1] > 70)
            {
                studentrecord(&(*PDE), roll_number, marks, &(*indx), 2);
            }
        }
    }
    insertion_sort(stud, *s);
    insertion_sort(PDE, *indx);
}

// search using binary search
int search(struct student *stud, int roll_number, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (stud[mid].roll_number == roll_number)
            return mid;

        else if (stud[mid].roll_number > roll_number)
            search(stud, roll_number, low, mid - 1);

        else
            search(stud, roll_number, mid + 1, high);
    }
    else
        return -1;
}

int main()
{
    struct student records[100];
    struct student PDE[100];
    FILE *ptr;
    ptr = fopen("input.txt", "r");
    int i;
    fscanf(ptr, "%d", &i);
    int n = 0, indx = 0;
    while (i--)
    {
        int roll_number, marks[3];
        fscanf(ptr, "%d", &roll_number);
        for (int t = 0; t < 3; t++)
        {
            fscanf(ptr, "%d", &marks[t]);
        }
        if (roll_number / N >= 10 && roll_number / N < 14)
        {
            studentrecord(records, roll_number, marks, &n, 3);
            if (marks[0] < 40 && marks[1] > 70)
            {
                studentrecord(PDE, roll_number, marks, &indx, 2);
            }
        }
    }
    fclose(ptr);
    quick_sort(records, 0, n - 1);
    quick_sort(PDE, 0, indx - 1);
    print_record(records, 0, n - 1, 3);
    print_record(PDE, 0, indx - 1, 2);
    int ch;
    while (1)
    {
        printf("enter your choice : ");
        printf("\n1.insert\n2.search\n3.displaymain\n4.displayPDE\n5.exit\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            insert(records, PDE, &n, &indx);
            print_record(records, 0, n - 1, 3);
            print_record(PDE, 0, indx - 1, 2);
        }
        else if (ch == 2)
        {
            int x;
            scanf("%d", &x);
            int index = search(records, x, 0, n - 1);
            if (index != -1)
                print_record(records, index, index, 3);
            else
                printf("records not found\n");
        }
        else if (ch == 3)
        {
            print_record(records, 0, n - 1, 3);
        }
        else if (ch == 4)
        {
            print_record(PDE, 0, indx - 1, 2);
        }
        else if (ch == 5)
        {
            break;
        }
        else
        {
            printf("\ntry again !!\n");
        }
    }
    return 0;
}
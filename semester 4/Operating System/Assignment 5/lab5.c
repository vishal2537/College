#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int MAX_PROCESS;
int MAX_RESOURCES;
int finished = 0;

bool check_deadlock(bool finish[MAX_PROCESS], int request[MAX_PROCESS][MAX_RESOURCES], int available[MAX_RESOURCES], int allocation[MAX_PROCESS][MAX_RESOURCES]);
void safe_sequence(bool finish[MAX_PROCESS], int request[MAX_PROCESS][MAX_RESOURCES], int available[MAX_RESOURCES], int allocation[MAX_PROCESS][MAX_RESOURCES]);

int main()
{
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\tENTER MAX_PROCESS: ");
    scanf("%d", &MAX_PROCESS);
    printf("\t\tENTER MAX_RESOURCES: ");
    scanf("%d", &MAX_RESOURCES);

    int allocation[MAX_PROCESS][MAX_RESOURCES];
    int request[MAX_PROCESS][MAX_RESOURCES];
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\tENTER ALLOCATION MATRIX :\n");

    for (int i = 0; i < MAX_PROCESS; i++)
    {
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\tENTER REQUEST MATRIX :\n");

    for (int i = 0; i < MAX_PROCESS; i++)
    {
        for (int j = 0; j < MAX_RESOURCES; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    int total[MAX_RESOURCES];
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\tENTER TOTAL INSTACE OF RESOURCES :\n");
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        printf("R%d : ", i);
        scanf("%d", &total[i]);
    }
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    int available[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        available[i] = total[i];
        for (int j = 0; j < MAX_PROCESS; j++)
        {
            available[i] -= allocation[j][i];
            if (available[i] < 0)
            {
                printf("NOT ENOUGH RESOURCES");
                return 1;
            }
        }
    }

    bool finish[MAX_PROCESS];
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        finish[i] = false;
    }

    if (check_deadlock(finish, request, available, allocation))
    {
        printf("\t\tNO DEADLOCK\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        return 0;
    }
    else
    {
        printf("\t\tDEADLOCK\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        safe_sequence(finish, request, available, allocation);
    }
    return 0;
}

bool check_deadlock(bool finish[MAX_PROCESS], int request[MAX_PROCESS][MAX_RESOURCES], int available[MAX_RESOURCES], int allocation[MAX_PROCESS][MAX_RESOURCES])
{
    while (finished < MAX_PROCESS)
    {
        bool deadlock = true;
        for (int i = 0; i < MAX_PROCESS; i++)
        {
            if (finish[i])
                continue;
            bool allowed = true;
            for (int j = 0; j < MAX_RESOURCES; j++)
            {
                if (request[i][j] > available[j])
                {
                    allowed = false;
                    break;
                }
            }
            if (!allowed)
                continue;
            for (int j = 0; j < MAX_RESOURCES; j++)
            {
                available[j] += allocation[i][j];
            }
            finish[i] = 1;
            printf("\tSAFE SEQUENCE : P%d \n", i);
            finished++;
            deadlock = false;
        }
        if (deadlock)
        {
            return false;
        }
    }
    return true;
}

void safe_sequence(bool finish[MAX_PROCESS], int request[MAX_PROCESS][MAX_RESOURCES], int available[MAX_RESOURCES], int allocation[MAX_PROCESS][MAX_RESOURCES])
{
    bool terminated_Set[MAX_PROCESS];
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        terminated_Set[i] = false;
    }
    while (!check_deadlock(finish, request, available, allocation))
    {
        int requested[MAX_RESOURCES];
        for (int i = 0; i < MAX_RESOURCES; i++)
        {
            requested[i] = 0;
            for (int j = 0; j < MAX_PROCESS; j++)
            {
                if (finish[j])
                    continue;
                requested[i] += request[j][i];
            }
        }
        int max_resource = 0, indx;
        for (int i = 0; i < MAX_PROCESS; i++)
        {
            if (finish[i])
            {
                continue;
            }
            int current_max_resources = 0;
            for (int j = 0; j < MAX_RESOURCES; j++)
            {
                if ((requested[j] - request[i][j]) > allocation[i][j])
                    current_max_resources += allocation[i][j];
                else
                    current_max_resources += (requested[j] - request[i][j]);
            }
            if (max_resource < current_max_resources)
            {
                max_resource = current_max_resources;
                indx = i;
            }
        }
        for (int i = 0; i < MAX_RESOURCES; i++)
        {
            available[i] += allocation[indx][i];
        }
        terminated_Set[indx] = true;
        finish[indx] = true;
        finished++;
    }
    printf("PROCESS WHOSE TERMINATION ENDS DEADLOCK : \n");
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        if (terminated_Set[i])
        {
            printf("\t\tP%d \n", i);
        }
    }
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

// allocationmatrix
// 0 1 0
// 1 0 2
// 1 3 1
// 0 0 1
// 4 2 3

// request matrix
// 1 1 0
// 1 2 3
// 3 1 1
// 0 0 1
// 3 2 2

// 2 -- example

// 10 5 7

// alloc
// 0 1 0
// 2 0 0
// 3 0 2
// 2 1 1
// 0 0 2

// request
//  7 4 3
//  1 4 2
//  6 0 0
//  0 1 3
//  4 4 1

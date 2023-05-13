#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_PROCESS 100
int N = 0;
struct Process
{
    char name[20];
    int arrival;
    int cpuburst;
    int turnaround;
    int wait;
};

struct Process processtable[MAX_PROCESS];

int comparator(const void *p, const void *q)
{
    return ((struct Process *)p)->arrival < ((struct Process *)q)->arrival;
}

void ReadProcessTable(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR IN OPENING FILE\n");
        exit(1);
    }
    int i = N;
    while (i < MAX_PROCESS && fscanf(fp, "%s %d %d", processtable[i].name, &processtable[i].arrival, &processtable[i].cpuburst) != EOF)
    {
        processtable[i].turnaround = 0;
        processtable[i].wait = 0;
        i++;
    }
    N = i;
    fclose(fp);
}

void PrintProcessTable()
{
    printf("PROCESS NAME \tARRIVAL TIME\tCPU BURST\tTURNAROUND TIME\tWAIT TIME\n");
    for (int i = 0; i < N; i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", processtable[i].name, processtable[i].arrival, processtable[i].cpuburst, processtable[i].turnaround, processtable[i].wait);
    }
}

void FCFS()
{
    printf("\tFIRST COME FIRST SERVE\n");
    qsort(processtable, N, sizeof(struct Process), comparator);
    int curr_time = 0;
    for (int i = 0; i < N; i++)
    {
        if (curr_time >= processtable[i].arrival)
        {
            curr_time += processtable[i].cpuburst;
        }
        else
            curr_time = processtable[i].arrival + processtable[i].cpuburst;
        processtable[i].turnaround = curr_time - processtable[i].arrival;
        processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
        printf("[%d-%d]\t%s\tRUNNING\n", curr_time - processtable[i].cpuburst, curr_time, processtable[i].name);
    }
}

void RR(int quantum)
{
    printf("\tROUND ROBIN\n");
    qsort(processtable, N, sizeof(struct Process), comparator);

    int cpuburstcopy[N];
    int n = 0;
    int current_time = processtable[0].arrival;

    for (int i = 0; i < N; i++)
    {
        cpuburstcopy[i] = processtable[i].cpuburst;
    }

    int i = 0;
    while (n < N)
    {
        if (cpuburstcopy[i] > 0 && processtable[i].arrival <= current_time)
        {
            if (cpuburstcopy[i] > quantum)
            {
                printf("[%d-%d]\t%s\tRUNNING\n", current_time, current_time + quantum, processtable[i].name);
                current_time += quantum;
                cpuburstcopy[i] -= quantum;
            }
            else
            {
                printf("[%d - %d]\t%s\tRUNNING\n", current_time, current_time + cpuburstcopy[i], processtable[i].name);
                current_time += cpuburstcopy[i];
                processtable[i].turnaround = current_time - processtable[i].arrival;
                processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
                cpuburstcopy[i] = 0;
                n++;
            }
        }
        i = (i + 1) % N;
    }
}

void SRBF()
{
    qsort(processtable, N, sizeof(struct Process), comparator);
    printf("\tSHORTEST REMAINING BURST FIRST\n");
    int current_time = processtable[0].arrival;
    int n = 0;
    int cpuburstcopy[N];
    int shortest, prevShortest = -1;
    int start = current_time;

    for (int i = 0; i < N; i++)
    {
        cpuburstcopy[i] = processtable[i].cpuburst;
    }

    while (n < N)
    {
        int shortest_remaining_burst = INT_MAX;

        for (int i = 0; i < N; i++)
        {
            if (processtable[i].arrival <= current_time && cpuburstcopy[i] > 0)
            {
                if (cpuburstcopy[i] < shortest_remaining_burst)
                {
                    shortest = i;
                    shortest_remaining_burst = cpuburstcopy[i];
                }
            }
        }

        cpuburstcopy[shortest]--;
        current_time++;
        if (cpuburstcopy[shortest] == 0)
        {
            printf("[%d-%d]\t%s\tRUNNING-FIRST\n", start, current_time, processtable[shortest].name);
            processtable[shortest].turnaround = current_time - processtable[shortest].arrival;
            processtable[shortest].wait = processtable[shortest].turnaround - processtable[shortest].cpuburst;
            n++;
            start = current_time;
        }
        else if (prevShortest != -1 && prevShortest != shortest && cpuburstcopy[prevShortest] != 0)
        {
            printf("[%d-%d]\t%s\tRUNNING\n", start, current_time - 1, processtable[prevShortest].name);
            start = current_time - 1;
        }
        prevShortest = shortest;
    }
}

void PrintStatistics()
{
    int total_turnaround = 0, total_wait = 0;
    for (int i = 0; i < N; i++)
    {
        total_turnaround += processtable[i].turnaround;
        total_wait += processtable[i].wait;
    }
    float avg_turnaround = (float)total_turnaround / N;
    float avg_wait = (float)total_wait / N;

    printf("\nTURN AROUND TIME:\t");
    for (int i = 0; i < N; i++)
    {
        printf("%s[%d]", processtable[i].name, processtable[i].turnaround);
        if (i != N - 1)
        {
            printf(", ");
        }
    }
    printf("\nWAIT TIME:\t\t");
    for (int i = 0; i < N; i++)
    {
        printf("%s[%d]", processtable[i].name, processtable[i].wait);
        if (i != N - 1)
        {
            printf(", ");
        }
    }
    printf("\n\nAVERAGE TURNAROUND TIME: %.2f\n", avg_turnaround);
    printf("AVERAGE WAIT TIME: %.2f\n", avg_wait);
    printf("\nHIT ANY KEY TO CONTINUE...\n\n");
    getchar();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("INVALID ARG\n");
        return -1;
    }
    ReadProcessTable(argv[1]);
    PrintProcessTable();
    int algorithm;
    while (1)
    {

        printf("\tCPU SCHEDULING SIMULATION\n");
        printf("SELECT ALGORITHM [1,2,3 or 4]:\n");
        printf("1. FCFS\n");
        printf("2. RR\n");
        printf("3. SRBF\n");
        printf("4. Exit\n");

        scanf("%d", &algorithm);
    
        switch (algorithm)
        {
        case 1:
            FCFS();
            PrintStatistics();
            break;
        case 2:
        {
            int timeQuantum;
            printf("ENTER TIME QUANTUM: ");
            scanf("%d", &timeQuantum);
            RR(timeQuantum);
            PrintStatistics();
            break;
        }
        case 3:
            SRBF();
            PrintStatistics();
            break;
        case 4:
            return 0;
        default:
            printf("invalid inout\n");
            break;
        }
    }

    return 0;
}
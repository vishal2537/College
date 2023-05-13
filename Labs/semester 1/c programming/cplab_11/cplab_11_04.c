#include <stdio.h>

struct time
{
   int hrs;
   int mins;
   int seconds;
};

int main()
{
   struct time start, stop, diff;

   printf("Enter start time in hr:min:sec form: ");
   scanf("%d%d%d", &start.hrs, &start.mins, &start.seconds);

   printf("Enter stop time in hr:min:sec form: ");
   scanf("%d%d%d", &stop.hrs, &stop.mins, &stop.seconds);

   if (start.seconds > stop.seconds)
   {
      stop.seconds += 60;
      --stop.mins;
   }

   if (start.mins > stop.mins)
   {
      stop.mins += 60;
      --stop.hrs;
   }

   diff.seconds = stop.seconds - start.seconds;
   diff.mins = stop.mins - start.mins;
   diff.hrs = stop.hrs - start.hrs;

   printf("Difference between two time period = %d : %d : %d", diff.hrs, diff.mins, diff.seconds);
   return 0;
}
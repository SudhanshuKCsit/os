
#include <stdio.h>
#include <stdlib.h>

typedef struct rr
{
   int pid, bt, tat, wt, bt_bal;
} RR;

int main()
{
   RR p[50];
   int n, i, j, tq;
   int sum_wt = 0, sum_tat = 0, sum_bt = 0, tq_used = 0;
   printf("Enter the process:\n");
   scanf("%d", &n);
   for (i = 0; i < n; i++)
   {
      printf("Enter the brust time for process  %d :\t", i + 1);
      p[i].pid = i + 1;
      scanf("%d", &p[i].bt);
      p[i].bt_bal = p[i].bt;
   }
   printf("Enter the quantum time:\t");
   scanf("%d", &tq);
   for (i = 0; i < n; i++)
      sum_bt += p[i].bt;
   printf("Sum of brust time is %d", sum_bt);
   do
   {
      for (i = 0; i < n; i++)
      {
         if (p[i].bt_bal > 0 && p[i].bt_bal <= tq)
         {
            tq_used += p[i].bt_bal;
            p[i].tat = tq_used;
            p[i].wt = p[i].tat - p[i].bt;
            p[i].bt_bal = 0;
         }
         else if (p[i].bt_bal > 0)
         {
            tq_used += tq;
            p[i].bt_bal -= tq;
         }
         else if (p[i].bt_bal < 0)
         {
            printf("Error brust time is in negative:\n");
            exit(1);
         }
      }
   } while (tq_used != sum_bt);
   for (i = 0; i < n; i++)
   {
      sum_wt += p[i].wt;
      sum_tat += p[i].tat;
   }
   printf("\nTotal waiting time = % d\n", sum_wt);
   printf("Average waiting time = % .2f\n", (float)sum_wt / n);
   printf("\n");
   printf("Total turnaround time = % d\n", sum_tat);
   printf("Average turnaround time = % .2f\n", (float)sum_tat / n);
}
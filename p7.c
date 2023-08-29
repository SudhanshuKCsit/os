#include <stdio.h>

struct process
{
   int max[20], alloc[20], need[20];
} p[6];

int avail[20], n, r, safe[20];
int get_data();
int bankers();
int main()
{
   get_data();
   bankers();
}
int get_data()
{
   int i, j;
   printf("Enter the process:\t");
   scanf("%d", &n);
   printf("Enter the resources:\t");
   scanf("%d", &r);
   printf("Enter the allocated resources:\n");
   for (i = 0; i < n; i++)
   {
      printf("process p%d", i);
      for (j = 0; j < r; j++)
         scanf("%d", &p[i].alloc[j]);
   }
   printf("Enter max of each process\n");
   for (i = 0; i < n; i++)
   {
      printf("process p%d", i);
      for (j = 0; j < r; j++)
         scanf("%d", &p[i].max[j]);
   }
   printf("Enter the current available resources\n");
   for (i = 0; i < r; i++)
      scanf("%d", &avail[i]);
   printf("Need Matrix\n");
   for (i = 0; i < n; i++)
   {
      for (j = 0; j < r; j++)
      {
         p[i].need[j] = p[i].max[j] - p[i].alloc[j];
         printf("%d\t", p[i].need[j]);
      }
   }
}
int bankers()
{
   int flag, c = 0, finish[10], i, j, f, s;
   for (i = 0; i < n; i++)
      finish[i] = 0;
   do
   {
      f = 0;
      for (i = 0; i < n; i++)
      {
         for (j = 0; j < r; j++)
         {
            flag = 0;
            if (p[i].need[j] > avail[j])
            {
               flag = 1;
               break;
            }
         }
         if (flag == 0 && finish[i] == 0)
         {
            f = 1;
            printf("\nafter process p%dAvailable resources =", i);
            for (j = 0; j < r; j++)
            {
               p[i].need[j] = 0;
               avail[j] = p[i].alloc[j] + avail[j];
               printf("%d\t", avail[j]);
            }
            printf("\n");
            safe[c++] = i;
            finish[i] = 1;
         }
      }
      if (f == 0)
         break;
   } while (f == 1);
   s = 1;
   for (i = 0; i < n; i++)
      if (finish[i] == 0)
      {
         printf("cannot allocate request resources for process p%d", i);
         s = 0;
         break;
      }
   if (s != 0)
   {
      printf("---safe state--\n");
      printf("safe sequence:\n");
      for (i = 0; i < c; i++)
         printf("p%d\t", safe[i]);
      printf("\n");
   }
   else
      printf("---unsafe state---\n");
}

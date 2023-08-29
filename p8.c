#include <stdio.h>

int main()
{
   int i, m, n, tot, s[20];
   printf("total memory size:");
   scanf("%d", &tot);
   printf("number of pages:");
   scanf("%d", &n);
   printf("memory for os:");
   scanf("%d", &m);
   for (i = 0; i < n; i++)
   {
      printf("size of page %d:", i + 1);
      scanf("%d", &s[i]);
   }
   tot = tot - m;
   for (i = 0; i < n; i++)
   {
      if (tot >= s[i])
      {
         printf("allocate page %d\n", i + 1);
         tot = tot - s[i];
      }
      else
      {
         printf("process p %d is blocked \n", i + 1);
      }
   }
   printf("external fragmentation is :%d\n", tot);
}
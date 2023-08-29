#include <stdio.h>
#include <omp.h>

int fib(int n)
{
   if (n < 2)
      return n;
   else
      return fib(n - 1) + fib(n - 2);
}
int main()
{
   int fibnum[100], i, j, n;
   printf("Enter the series limit: ");
   scanf("%d", &n);

#pragma omp parallel num_threads(2) shared(fibnum, n) private(i, j) // openmp directive
   {
      if (omp_get_thread_num() == 0)
      {
         printf("There are %d threads\n", omp_get_num_threads());
         printf("Thread %d is generating number.\n", omp_get_thread_num());
         for (i = 0; i <= n; i++)
            fibnum[i] = fib(i);
      }

#pragma omp barrier // To make the second thread wait till first one finishes the work
      if (omp_get_thread_num() != 0)
      {
         printf("Thread %d is printing number.\n", omp_get_thread_num());
         for (j = 1; j <= n; j++)
            printf("%d\t", fibnum[j]);
         printf("\n");
      }
   }
   return 0;
}
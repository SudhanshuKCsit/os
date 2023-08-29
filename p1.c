#include <stdio.h>
#include <unistd.h>

int main()
{
   int ch;
   char cmd[50];
   int pid = fork();
   if (pid == 0)
   {
      printf("child process:\n");
      do
      {
         printf("enter the command\n");
         scanf("%s", cmd);
         system(cmd);
         printf("enter 1 to continue or 0 to exit\n");
         scanf("%d", &ch);
      } while (ch != 0);
   }
   else
      wait();
}
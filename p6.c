#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
   int l = link(argv[1], argv[2]);
   if (l == 0)
   {
      printf("hard link created successfully\n");
   }
   int sl = symlink(argv[3], argv[4]);
   if (sl == 0)
   {
      printf("Soft link created successfully\n");
   }
   int mode = access("/mnt/c/Users/Sudhanshu Kumar/Desktop/os/b_test.txt", 0);
   if (mode)
      printf("file does not exist\n");
   else
   {
      mode = access("/mnt/c/Users/Sudhanshu Kumar/Desktop/os/b_test.txt", 2);
      if (mode)
         printf("file cannot be written to\n");
      else
         printf("file can be written to\n");
      mode = access("/mnt/c/Users/Sudhanshu Kumar/Desktop/os/b_test.txt", 4);
      if (mode)
         printf("file cannot be read\n");
      else
         printf("file can be read\n");
      mode = access("/mnt/c/Users/Sudhanshu Kumar/Desktop/os/b_test.txt", 6);
      if (mode)
         printf("file cannot be read/written to \n");
      else
         printf("file can be read/written to \n");
      system("ls -qAi|awk '{print $l}'|sort |uniq -d|wc -l");
   }
   return EXIT_SUCCESS;
}

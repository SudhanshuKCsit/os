#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   struct stat filestat;
   int hl = link(argv[1], argv[2]);
   if (hl == 0)
      printf("hard link created successfully\n");
   int sl = symlink(argv[3], argv[4]);
   if (sl == 0)
      printf("soft link created successfully\n");
   int result = stat(argv[1], &filestat);
   if (result != 0)
   {
      printf("error getting file status \n");
      exit(EXIT_FAILURE);
   }
   printf("file size :%ld bytes\n", filestat.st_size);
   printf("number of hard links :%ld\n", filestat.st_nlink);
   printf("inode number : %ld\n", filestat.st_ino);
   printf("file permissions :%u\n", filestat.st_mode & 0777);
   printf("owner user id : %u\n", filestat.st_uid);
   printf("owner group id :%u\n", filestat.st_gid);
   result = stat(argv[2], &filestat);
   if (result != 0)
   {
      printf("error getting file status");
      exit(EXIT_FAILURE);
   }
   printf("no of hard links :%ld\n", filestat.st_nlink);
   return EXIT_SUCCESS;
}
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int     fd;
   size_t  size0 = 14, size;
   char* string = malloc(size0 + 1);

   umask(0);

   if(read(0, string, size0) < size0)
   {
       printf("Error reading\n");
   }

   if((fd = open("myfile", O_WRONLY | O_CREAT, 0666)) < 0){
     printf("Can\'t open file\n");
     exit(-1);
   }

   size = write(fd, string, 14);

   if(size != 14){
     printf("Can\'t write all string\n");
     exit(-1);
   }

   if(close(fd) < 0){
     printf("Can\'t close file\n");
   }

   return 0;
}

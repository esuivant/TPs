#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAP_SIZE 4096

int main(int argc, char **argv)
{
   char  *base_addr = NULL;
   char  *curr_addr = NULL;
   char  *filename  = NULL;
   int    str_len   = 0; 
   int    fd,fd2,i;

   fprintf(stdout,"PID : %i\n",getpid());

   filename = argv[1];
   str_len = strlen(argv[2])+1;

   fd = open(filename,O_RDWR);
   
   base_addr = (char *)mmap(NULL, MAP_SIZE , PROT_READ | PROT_WRITE, MAP_SHARED , fd , 0);
   curr_addr = base_addr;

   fprintf(stdout,"String is : %s\n",curr_addr);
      
   fd2 = open("/tmp/montube",O_RDONLY);
   fprintf(stdout,"String is : %s\n",curr_addr);
   fflush(stdout);
   
   close(fd2);
   close(fd);
   munmap((void *)base_addr,MAP_SIZE);
   return 0;
}

  

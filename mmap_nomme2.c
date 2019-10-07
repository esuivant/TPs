#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{

   pid_t pid, pid2;
   int fd;

   mkfifo("/tmp/montube",S_IRUSR|S_IWUSR);
   fd = open(argv[1],O_RDWR|O_CREAT|O_EXCL,S_IRUSR|S_IWUSR);
   if (fd != -1) {ftruncate(fd,4096);
   close(fd);}

   pid = fork();

   if(pid > 0) {
    pid2 = fork();
    if (pid2 == 0) {
	     execlp("./mmap3","mmap3",argv[1],argv[2],NULL);
    }
    else if (pid2 > 0) {
      wait(NULL);
	    wait(NULL);
    }
  }
  else if (pid == 0){
    execlp("./mmap4","mmap4",argv[1],argv[2],NULL);
  }

  unlink("/tmp/montube");
  unlink(argv[1]);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define PIPE_SIZE 1024


int main(int argc, char const *argv[]) {
  int pipefd[2];
  char *buf[PIPE_SIZE];
  pid = getpid();
  char *buffer = pid;
  int n = 7;
  mkfifo("./tube1", S_IRWXU);
  int fdl = open("./tube1", O_WRONLY);
  write(fdl, buf, PIPE_SIZE);
  printf("%s\n", buf);
  exit(EXIT_SUCCESS);
  return 0;
}

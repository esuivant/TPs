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
  char *buffer = "Je suis ton fils";
  int n = strlen(buffer);
  pipe(pipefd);
  int fdl = pipefd[0];
  int fde = pipefd[1];
  pid_t pid = fork();

  if (pid == 0){
    close(fdl);
    write(fde, buffer, n);
    exit(EXIT_SUCCESS);
  }
  else if (pid > 0){
    close(fde);
    read(fdl, buf, PIPE_SIZE);
    printf("%s\n", buf);
    wait(NULL);
    exit(EXIT_SUCCESS);
  }
  return 0;
}

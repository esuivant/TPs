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
  char *buffer = "bonjour";
  int n = 7;
  mkfifo("./coucou", S_IRWXU);

  pid_t pid = fork();

  if (pid == 0){
    int fde = open("./coucou", O_RDONLY);
    write(fde, buffer, n);
    exit(EXIT_SUCCESS);
  }
  else if (pid > 0){
    int fdl = open("./coucou", O_WRONLY);
    read(fdl, buf, PIPE_SIZE);
    printf("%s\n", buf);
    wait(NULL);
    exit(EXIT_SUCCESS);
  }
  return 0;
}

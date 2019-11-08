#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define SIGKILL 9

int main(int argc, char const *argv[]) {
  int pid_fils;
  printf("mon pid : %d \n ", getpid());
  pid_fils = fork();
  if (pid_fils > 0) {
    printf("pere  : %d \n ", getpid());
    while (1);
    wait(NULL);
  } else if (pid_fils == 0) {
    printf("fils : %d \n ", getpid());
    kill(getppid(), SIGKILL);
  }

  return 0;
}

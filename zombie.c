#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[]) {
  pid_t pid_fils = fork();

  if (0 == pid_fils) {
    int toto = 0;
    while(++toto);
    printf("pid de son pere : %d. \n", getppid());
    exit(EXIT_SUCCESS);
  }
  else if (pid_fils > 0) {
    printf("pid courrant : %d. \n", getpid());
    exit(EXIT_SUCCESS);

  }
  return 0;
}

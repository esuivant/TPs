#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  pid_t pid_fils = fork();

  if (pid_fils > 0) {
    int toto = 0;
    int status;

    while(++toto);
    wait(&status);
    printf("valeur de retour du fils : %d.\n", WEXITSTATUS(status));
    exit(EXIT_SUCCESS);

  } else if (0 == pid_fils) {
    return 33;
  }

  exit(EXIT_SUCCESS);
  return 0;
}

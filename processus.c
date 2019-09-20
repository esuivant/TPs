#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {
//  pid_t pid = getpid();

//  pid_t pid_fils = fork();

  /* if (0 == pid_fils) {
    printf("Papa : %i \n", getppid());
  } else if (pid_fils > 0) {
    printf("Fiston : %i \n", pid_fils);
  } */

  int i;
  pid_t pid;
  for (  i = 0 ; i < 10;  i++) {
    pid = fork();
    printf("pid fils : %i \n", pid);
    if (0==pid){
      break;
    }
  }

  
  return 0;
}

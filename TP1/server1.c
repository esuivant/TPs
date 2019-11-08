#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

#define SIGUSR1 10
#define SIGCHLD 17
#define BUFFER 1024

void traitant(int i){
  if (i == 10) {
    const char *buf ="signal SIGUSR1 recu\n";
    int pid_fils = fork();
    printf("hello\n" );
    if (pid_fils == 0) { /* code du fils */
    /*  int fdl = open(pathname2, O_WRONLY);
      int fde = open(pathname1, O_RDONLY); */
    }
  }
  else if (i == 17) { /*SIGCHLD */
    wait(NULL);}
  else if (i == 0){
    exit;
  }
}


int main(int argc, char const *argv[]) {
  printf("mon pid : %d\n",getpid() );
  struct sigaction sig;
  sig.sa_handler = *traitant;
  sig.sa_flags = 0;

  sigaction(SIGUSR1,&sig, NULL);
  sigaction(SIGCHLD,&sig, NULL);
  sigaction(SA_SIGINFO, &sig, NULL);
  while(1);
  return 0;
}

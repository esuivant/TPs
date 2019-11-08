#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

#define SIGUSR1 10

#define BUFFER 1024
void traitant(int i){
  if (i == 10) {
    const char *buf ="signal SIGUSR1 recu\n";
    int count = 21;
    write(STDOUT_FILENO,buf, count);
  }
}

int main(int argc, char const *argv[]) {
  printf("mon pid : %d\n",getpid() );
  struct sigaction sig;
  sig.sa_handler = *traitant;
  sig.sa_flags = 0;

  sigset_t *set;
  //sigfillset(set);
  //sigdelset(set, SIGUSR1);

  sigemptyset(set);
  sigaddset(set, SIGUSR1);

  sigprocmask(SIG_SETMASK, set, NULL);

  sig.sa_mask = set;


  sigaction(SIGUSR1,&sig, NULL);

  while(1);
  return 0;
}

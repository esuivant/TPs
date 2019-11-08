#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIPE_SIZE 1024
#define BUFFER 1024
#define SIGUSR1 10

int main(int argc, char  *argv) {

  int pid_server = argv[1];

  int pipefd[2];

  int pid = getpid();
  char chemin[100]= "./../../../../tmp/PIPE_\0";
  char m1[10];
  char f1[10];
  char f2[10];

  unsigned int num1 = rand();
  unsigned int num2;
  do {
    num2 = abs(rand());
  } while(num1==num2);
  printf("num 1 %d, num 2 %d\n",num1, num2);

  sprintf(m1,"%d",pid);
  sprintf(f1,"%d",num1);
  sprintf(f2,"%d",num2);

  char * pathname1 = strcat(chemin, m1);
  pathname1 = strcat(pathname1, "_");
  pathname1 = strcat(pathname1, f1);

  mkfifo(pathname1, S_IRWXU);
  int fdl = open(pathname1, O_WRONLY,O_NONBLOCK);

  char * pathname2 = '\0';
  pathname2 = strcat(chemin, m1);
  pathname2 = strcat(pathname2, "_");
  pathname2 = strcat(pathname2, f2);

  mkfifo(pathname2, S_IRWXU);
  int fde = open(pathname2, O_RDONLY,O_NONBLOCK);

  union sigval valeur;
  valeur.sival_int = num1;

  sigqueue(pid_server, SIGUSR1,(const union sigval) valeur);

  char *buf[PIPE_SIZE];
  *buf = "bonjour";
  write(fdl, buf, PIPE_SIZE);

  kill(pid_server,SIGUSR1);

  close(fdl);
  close(fde);

  return 0;
}

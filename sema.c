#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <semaphore.h>

sem_t sem;

int main(int argc, char const *argv[]) {
  sem_t sem;
  sem_init(&sem,0 ,0 );
  int i;
  pid_t pid;
  for (  i = 0 ; i < 10;  i++) {
    pid = fork();
    if (pid > 0) {
      sem_trywait(&sem);
      fprintf(stdout,"fils n°%d : j'ai un jeton ; mon pid : %d\n", i, pid);
    } else if (0==pid){
      break;
    }
  }

  if (pid > 0) {
    i = 0;
    while(i<10){
    //  sem_post(sem);
    //  fprintf(stdout,"j'ai mis le jeton n°%d dans la boite \n", i);
      i++;
    }
  }
  sem_destroy(&sem);
}

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void * fonc1(void * arg){
  fprintf(stdout,"Reçu : %i\n", *(int *)arg);

  return NULL;
}

void * fonc2(void * arg){
  fprintf(stdout,"Je suis la fonction 2\n");
  return NULL;
}

int main(int argc, char const *argv[]) {
  int i; // pas globale mais partagée par tout le monde
  int mon_i[10];
  void * retval;
  pthread_t tid[10];
  for (i =0; i<10; i++){
    mon_i[i]=i;
    if (pthread_create(&tid[i], NULL, fonc1,(void *)&mon_i[i])!=0){
      perror("pthread_create1()");
      exit(EXIT_FAILURE);
    }
  }
  sleep(10);
  //pthread_exit(retval);
  return 0;
}

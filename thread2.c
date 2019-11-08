#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void * fonc1(void * arg){
  fprintf(stdout,"Je suis la fonction 1\n");

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
  pthread_t tid1;
  pthread_t tid2;
  int pjoin;

  if (pthread_create(&tid1, NULL, fonc1, NULL) !=0){
    perror("pthread_create1()");
    exit(EXIT_FAILURE);
  }
  if (pthread_create(&tid2, NULL, fonc2,NULL)!=0){
      perror("pthread_create1()");
      exit(EXIT_FAILURE);
  }

  pthread_exit(retval);

  if (pthread_join(tid2, (void **) retval) != 0){
    perror("pthread_join()");
    exit(EXIT_FAILURE);
  }

  return 0;
}

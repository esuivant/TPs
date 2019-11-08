#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <semaphore.h>

#define MIN_INIT 1000

typedef struct{
  int nb;
  int *t;
} Tdonnees ;

int tab[10] = {10, 25, 6, 4, 5, 44, 12, 36, 9, 40};
int min = MIN_INIT;
pthread_mutex_t mutex;



void * calcul_min(void * donnees){
  Tdonnees *d;
  int i;
  int m = MIN_INIT;
  d = (Tdonnees*) donnees;
  for (i=0; i<d->nb; i++) if ((d->t)[i]<m) m = (d->t)[i];
  pthread_mutex_lock(&mutex); // D ́ebut de section critique
  if (m<min) min=m;
  pthread_mutex_unlock(&mutex); // Fin de section critique

  return NULL;
}

int main(int argc, char const *argv[]) {
  int i, n = 5;
  Tdonnees d[n];
  pthread_t tid[n];

  for (i =0; i<n; i++) {
    d[i].nb = 2;
    d[i].t = &(tab[2*i]);
  }
  pthread_mutex_init(&mutex, NULL);
  for (i =0; i<n; i++){
    if (pthread_create(&tid[i], NULL, calcul_min,(void *)&d[i]) != 0){
      perror("pthread_create()");
      exit(EXIT_FAILURE);
    }
  }
  for (i =0; i<n; i++){
    if (pthread_join(tid[i], NULL) != 0){
      perror("pthread_join()");
      exit(EXIT_FAILURE);
    }
  }
  printf("Le tableau contient : {");
  for (i = 0; i < 10; i++) {
    printf("%d ", tab[i]);
  }
  printf("}\n");

  printf("min = %d \n", min);
  return 0;
}

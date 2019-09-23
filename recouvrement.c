#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  /*const char * tab = ("./simple",1, 2, NULL);
  execv("./simple",tab );
  return 0;*/ // version 1

  char ** my_args = malloc(2*sizeof(char *));
  my_args[0] = "./simple";
  my_args[1] = NULL;
  execv("./simple", my_args);
  return 0;
}

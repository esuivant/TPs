#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  const char * tab = ("./simple",1, 2, NULL);
  execv("./simple",tab );
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  const char * pathname =  "./fichier";
  int flags = O_RDWR;

  int fd = open(pathname, flags);
  printf("%d \n", fd);

  return 0;
}

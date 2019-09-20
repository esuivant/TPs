#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[]) {
  const char * pathname =  "./file";
  int flags = O_RDWR;
  mode_t mode = S_IRWXU;

  FILE * fichier = fopen(pathname, "r");

  int fd = open(pathname, flags);
  printf("%d \n", fd);

  close(fd);
  return 0;
}

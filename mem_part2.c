#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char const *argv[]) {
  const char * pathname =  "./fichier";
  int flags = O_RDWR;
  off_t length = 8*10^3;
  const void *buf = "hello \0";
  size_t count = 5;
  char *addr;

  int fd = open(pathname, flags);

  addr = mmap(NULL, length/2, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 2);
  if (addr == MAP_FAILED) {
    perror("mmap()");
  }

  write(fd, buf, count);




  return 0;
}

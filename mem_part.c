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
  const char *buf = "bonjour \0";
  size_t count = sizeof(buf);

  char *addr;

  int fd = open(pathname, flags);

  ftruncate(fd, length);

  addr = mmap(NULL, length/2, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap()");
  }

  write(fd, buf, count);


  return 0;
}

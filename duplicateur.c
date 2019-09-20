#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[]) {
  const char * pathname =  "./output.txt";
  int flags = O_RDWR;
  mode_t mode = S_IRWXU;


  int fd = open(pathname, flags);
  close(1);

  dup(fd);
  close(fd);

  printf("bonjour\n" );


  return 0;
}

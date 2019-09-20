#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLINE 1024


int main(int argc, char const *argv[]) {
  const char * pathname =  "./file";
  int flags = O_RDWR;
  mode_t mode = S_IRWXU;

  int fd = open(pathname, flags, mode);
  //printf("%d \n", fd);

  int entier = 0;
  const void * buf = &entier;

  int count = sizeof(entier);
  ssize_t sw = write(fd, (const void *) buf, (size_t) count);

  int f = open(pathname, flags, mode);
  char* buffer[MAXLINE];
  int len = sizeof(buffer);
  ssize_t sr = read(f, (void*) buffer, (size_t) len);


  printf("buff :%s len : %d sr :%d\n", buffer, len, sr);

  close(fd);

  return 0;
}

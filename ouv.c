#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char const *argv[]) {
  pid_t pid_fils = fork();

  if (pid_fils == 0) {

    const char * pathname =  "./file";
    int flags = O_CLOEXEC;
    int fd = open(pathname, flags);
    printf("%d \n", fd);

    char ** my_args = malloc(2*sizeof(char *));
    my_args[0] = "./ouverture";
    my_args[1] = NULL;
    execv("./ouverture", my_args);
  }
  else if (pid_fils > 0){
      wait(NULL);
  }
  exit(EXIT_SUCCESS);
  return 0;
}

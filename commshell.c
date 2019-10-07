#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  int fd[2];
  int pid;
  pipe(fd);
  pid = fork();

  if (pid > 0) { /* code du pere */
    close(fd[1]); /* on ferme l'extrémité qui ne sert pas*/
    close (STDIN_FILENO); /* redirection */
    dup(fd[0]);
    close(fd[0]);
    execlp("wc", "wc", "-l", NULL);
  }
  else if (0 == pid) { /* code du fils */
    int fd2[2];
    int pid2;
    pipe(fd2);
    pid2 = fork();
    if (pid2 > 0) { /* code du pere */
      close(fd[0]);
      close(fd2[1]);
      close(STDOUT_FILENO);
      dup(fd[1]);
      close(fd[1]);
      close(STDIN_FILENO);
      dup(fd2[0]);
      close(fd2[0]);
      execlp("grep", "grep","truc",NULL);
    }
    else if ( 0 == pid2){ /* code du fils */
      close(fd[0]);
      close(fd2[0]);
      close(STDOUT_FILENO);
      dup(fd2[1]);
      close(fd2[1]);
      execlp("cat","cat","toto.txt",NULL);
    }
  }
  return 0;
}

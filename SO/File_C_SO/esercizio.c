#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/signal.h>
#define N 50
int main(int argc, char const *argv[]) {
  int n,pid,fd[2],status;
  char nomefile[N],nomefilefiglio[N];
  pipe(fd);
  pid=fork();
  if(pid==0){
    close(fd[1]);
    read(fd[0],nomefilefiglio,sizeof(nomefilefiglio));
    printf("cioa %s\n",nomefilefiglio );
    execl("./contatore","contatore", nomefilefiglio, NULL);
  }
  close(fd[0]);
  scanf("%s", nomefile);
  write(fd[1],nomefile,sizeof(nomefile));
  wait(NULL);
  printf("Termine esecuzione figlio\n");
  exit(0);
}

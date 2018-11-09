//Soojin Choi
//Work 13: Fire up the bat signal
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

static void sighandler(int signo){

  if (signo == SIGINT){

    char * msg = "File Exited Due to SIGINT\n";
    int fd = open("text.txt", O_CREAT | O_WRONLY, 0777);
    write( fd, msg, 27 );
    close(fd);
    exit(getpid());
    
  }

  if (signo == SIGUSR1){

    printf("PID of parent process: %d\n", getppid());
    
  }

};

int main(){

  while (1){

    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    printf("PID: %d\n", getpid());
    sleep(1);

  }

}

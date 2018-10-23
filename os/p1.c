#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //wait
#include <stdlib.h> //exit
#include <sys/stat.h> //open
#include <sys/types.h>
#include <fcntl.h>

void sigint_handler(int signum)
{
  printf("sigint(%d) caught by pid=%d\n", signum, getpid());
}

int main()
{
  // Registering a handler to get from other process
  printf("my pid = %d, registered signal handler\n", getpid());
  
  signal(SIGINT, sigint_handler);

  while(1)
  {
    printf("Waiting for signal from other process...\n sleeping...\n");
   // sleep(10);
    pause();
  }

  return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //wait
#include <stdlib.h> //exit
#include <sys/stat.h> //open
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  // Send signal to other pid from cmd line arguments
  if(argc > 1)
  {
    int pid  = atoi(argv[1]);

    if(pid > 0)
    {
      printf("will send signal to pid=%d\n", pid);

      if(0 == kill(pid, SIGINT))
       printf("signal sent to pid %d\n", pid);
      else
       perror("Error sending signal\n");
    }
  }
  else
  {
    perror("Error in arguments");
  }

  return 0;
}

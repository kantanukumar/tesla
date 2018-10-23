#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //wait
#include <stdlib.h> //exit
#include <sys/stat.h> //open
#include <sys/types.h>
#include <fcntl.h>
#include <sys/resource.h>

func(int, int);

int main()
{

  printf("pid=%d, ppid=%d\n", getpid(), getppid());

  int shared = 1;

  struct rlimit limit = {0};
  if(getrlimit(RLIMIT_AS, &limit) == 0)
  {
   printf("getrlimit success cur=%u max=%u\n", limit.rlim_cur, limit.rlim_max);

  }
  
  func(2, 3);

}

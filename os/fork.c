#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //wait
#include <stdlib.h> //exit
#include <sys/stat.h> //open
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

void sigint_handler(int signum)
{
  printf("sigint(%d) caught by pid=%d\n", signum, getpid());
}
int main()
{

  printf("pid=%d, ppid=%d\n", getpid(), getppid());

  int shared = 1;

  if(fork())
  {
    printf("I am parent pid=%d\n", getpid());
    printf("Shared parent = %d\n", ++shared);
    printf("Parent sleeping...\n");
    int status = 0;
    int cpid = 0;

    signal(SIGINT, sigint_handler);
    // signal(SIGSEGV, SIG_IGN);
    signal(SIGSEGV, sigint_handler);

    char *ptr = "kantanu";
    ptr[2] = 't';

    cpid = wait(&status);
    if(WIFEXITED(status))
      printf("Child %d exited\n", cpid);

    sleep(50);
  }
  else
  {
    printf("I am child pid=%d\n", getpid());
    printf("Shared child = %d\n", ++shared);
    printf("child sleeping...\n");
    sleep(30);
    printf("Child exiting...\n");
    exit(0);
  }

#if 0
  printf("Parent process opening a fd\n");

  int fd = 0;

  fd = creat("tempfd", O_CREAT | O_RDWR | 0660);
  if(fd < 0)
  {
    printf("fd=%d, errno=%d\n", fd, errno);
    perror("File create failed\n");
  }

  fd = open("tempfd", O_RDWR);

  if(fd < 0)
  {
    printf("fd=%d, errno=%d\n", fd, errno);
    perror("File open failed\n");
  }
  else
   printf("fd = %d\n", fd);

  write(fd, "Write from parent\n", 20);

  char buf[24] = {0};

  read(fd, buf, 20);

  write(1, buf, 20);

  close(fd);
#endif


}

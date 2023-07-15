#include <unistd.h>

int main()
{
  int fd[2];

  int ret = pipe(fd);

  if(ret)
   return 1;

  long val = fpathconf(fd[0], _PC_PIPE_BUF);

  printf("Pipe buf = %ld\n", val);

  return 0;
}

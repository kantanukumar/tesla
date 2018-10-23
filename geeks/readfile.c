#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    perror("Expected 2 args, exit");
    return 1;
  }

  int rd_fd = 0;
  int wr_fd = 0;
  char *buf = NULL;
  struct stat st_buf;
  int i = 0;
  int nl_count = 0;

  if(0 == stat(argv[1], &st_buf))
  {
    printf("File %s exists and size = %lu\n", argv[1], st_buf.st_size);
    buf = (char*)malloc(sizeof(char) * (st_buf.st_size+1));
  }
  else
  {
    printf("File %s does not exist\n", argv[1]);
    return 1;
  }

  rd_fd = open(argv[1], O_RDONLY);

  if(rd_fd < 0)
  {
    printf("failed to open file %s\n", argv[1]);
    return 1;
  }

//  while(rd_fd != EOF)
  while(EOF != buf[i])
  {
    if(read(rd_fd, &buf[i], 1 /*sizeof(buf)*/))
    {
        printf("buf = %c\n", buf[i]);

        if('\n' == buf[i])
          nl_count++;  
        
        i++;
    }
    else
    {
      printf("Error reading %s\n", argv[1]);
      break;
    }
  }

  printf("Newline count = %d\n", nl_count);
  return 0;
}

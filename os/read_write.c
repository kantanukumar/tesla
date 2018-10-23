#include <unistd.h>
//#include <sys/types.h>
#include <fcntl.h>

int main()
{
  char ch='a';

  int fd = 0;
  int bytes = 0;

  fd = open("file.txt", O_CREAT|O_RDWR, 0660);

  if(fd < 0)
  {
    perror("error in file creation");
    return -1;
  }

  bytes = write(fd, &ch, 1);
  if(bytes > 0)
  {
    printf("write success, ch=%c\n", ch);
  }

  ch = 'k';

  //bytes = read(fd, &ch, 1);
  bytes = pread(fd, &ch, 1, 0);

  printf("seek_set=%u\n", SEEK_SET);
  printf("seek_cur=%u\n", SEEK_CUR);
  printf("seek_end=%u\n", SEEK_END);

  if(bytes > 0)
  {
    printf("read success, ch=%c\n", ch);
  }


  return 0;
}

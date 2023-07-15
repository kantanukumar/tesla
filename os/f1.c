#include <stdio.h>

extern int f2;

int main()
{
  printf("Main() is in file on f1.c, f2=%d\n", f2);

  func(__FILE__);

  return 0;
}

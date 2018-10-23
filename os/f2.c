#include <stdio.h>

int f2 = 2;

void func(const char* str)
{
  if(str)
  {
    printf("func() called from %s\n", str);
  }
  else
  {
    printf("Caller didn't pass his file name\n");
  }
}

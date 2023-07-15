#include <stdio.h>

int main()
{
  const volatile *ptr = 0xfffffffff00;

  *ptr = 1;

  return 0;
}

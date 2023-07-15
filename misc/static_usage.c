#include <stdio.h>

void fun(void);

static int s_i;
int main(int argc, char **argv)
{
  int i;

  printf("s_i is static addr=%p val=%d\n", &s_i, s_i);
  printf("i is non static addr=%p val=%d\n", &i, i);

  fun();
  modify_static();
	return 0;
}

void fun(void)
{
  printf("Try printing s_i=%d\n", s_i);
}

void modify_static(void)
{
  printf("s_i = %d\n", ++s_i);
}

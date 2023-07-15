#include <stdio.h>

int main(int argc, char **argv)
{
  int num = 0xFFFFFFFF;

  for(int i = (sizeof(int) * 8)-1; i >= 0 ; i--)
  {
    if(num & (1 << i))
     printf("1");
    else
     printf("0");

    if(!(i % 4))
     printf(" ");
  }

  printf("\n");

	return 0;
}

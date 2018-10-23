#include <stdio.h>

int main(int argc, char **argv)
{
  unsigned int i1 = 0xffffffff;
  unsigned int i2 = 0xffffffff;

  unsigned long long int sum = 0;

  sum = (unsigned long long int)i1 + (unsigned long long int)i2;

  printf("Sum = %llx\n", sum);
  
  printf("Sizeof sum = %d\n", sizeof(sum));

	return 0;
}

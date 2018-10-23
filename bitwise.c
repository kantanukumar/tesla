#include <stdio.h>

main()
{
	volatile int x = 0xa3;
	
	x = (x << 4) | (x >> 4);

  x = x << 1 >> 31;

	printf("x = %x\n", x);
}

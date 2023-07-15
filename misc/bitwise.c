#include <stdio.h>

main()
{
	// Swap two nibbles
	unsigned char x = 0xa3;
	x = (x << 4) | (x >> 4);
  printf("x = %x\n", x);

//  x = x << 1 >> 31; TODO??? I do not know, what this is ???

	int num = 0xa3;
	char i = 0;

	for(i = 7; i>=0; i--)
	{
		if(num & (1 << i))
		{
//			printf("Bit %d is set\n", i);
			printf("1\n");
		}
		else
		{
	//		printf("Bit %d is not set\n", i);
			printf("0\n");
		}
	
	}

	return 0;
}

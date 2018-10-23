#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int static_int;

int main(int argc, char **argv)
{
	char arr[128];

	char *dyn;

	while(1)
	{
		dyn = (char*)malloc(12800);

		char stack[1280] = {};

		printf("Keeps allocating new memeory...dyn=%p, stack=%p\n", dyn, stack);

		printf("Sleeps a second\n");

		usleep(1000000);

	}

	return 0;
}

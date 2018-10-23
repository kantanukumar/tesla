#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * mystrndup(char *str, int n)
{
	char *p;
	p = malloc(n);
	memcpy(p, str, n);

	return p;
}

int main(int argc, char **argv)
{
	char *dup;

	dup = mystrndup(argv[1], strlen(argv[1]));

	return 0;
}

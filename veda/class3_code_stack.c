#include <stdio.h>
#include <unistd.h>

int main()
{
	int a = 100;

	int b;

	char c;

	int read_fd = 0;
	char buf[48];

	int count = read(read_fd, buf, 48);
}

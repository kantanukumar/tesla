#include <stdio.h>

int refer(int *x)
{
	*x = 5;
	printf("Changed x=%d\n", x=(int*)2);
	// printf("Changed *x=%d\n", *x);
}

main()
{
	int *p;
	int **pp;

  	int x = 1;

	p = &x;

	//pp = &p;

	**pp = *p;

	refer(p);

	printf("*p =%p\n", *p);

}

int refer(int *x)
{
	printf("Changed x=%d\n", *x=2);
}

main()
{
	int *p;
  int x =1;
double array[10000];
	p = &x;

	refer(&x);

	printf("*p =%p\n", *p);

}

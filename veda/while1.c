int main()
{
	int i = 0;
	while(1)
	{
		i++;

		printf("i = %d\n", i);

		if(i > 4000000)
			i = 0;
	}
}

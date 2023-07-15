int main()
{
	int num;
	
	printf("Enter a number for factorial: ");
	scanf("%d", &num);

//	printf("Factorial of number %d is: %d\n", num, fact(num));
	printf("Factorial of number %d is: %d\n", num, bf_fact(num));
}

int fact(int num)
{
	if((num == 1) || (num == 0))
		return 1;
	else
		return num * fact(num-1);
}

int bf_fact(int num)
{
	if(num == 1)
	{
		return 1;
	}
	else
	{
		int fact = 1;
		while(num > 1)
		{
			fact = fact * num--;
		}
	}
}

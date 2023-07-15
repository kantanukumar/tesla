#include <stdio.h>

int factorial(int num)
{
  if(num < 0)
    return -1;
  else if(num == 0 || num == 1)
    return num;
  else
    return num * factorial(--num);
}

int main(int argc, char **argv)
{
  int num = 0;
  int fact = 0;

  printf("enter number ");
  scanf("%d", &num);

 // printf("factorial of '%d' = %d\n", num, factorial(num));

  fact = num;

  while(num)
  {
    if(num == 1)
    {
      break;
    }
    else
      fact = fact * --num;
  }

  printf("factorial of '%d' = %d\n", num, fact);

	return 0;
}

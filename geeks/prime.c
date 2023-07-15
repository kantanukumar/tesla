#include <stdio.h>

int main(int argc, char **argv)
{
  int num = 1;
  int isPrime = 1;

  while(num < 1000000)
  {
    for(int i = 2; i < num; i++)
    {
      if((num % i == 0))
      {
        isPrime = 0;
        break;
      }
      else
       isPrime = 1;
    }

    if(isPrime)
     printf("%d ", num);

    num++;

  }

  printf("\n");
	return 0;
}

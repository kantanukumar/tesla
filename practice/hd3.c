#include <stdio.h>
#include <math.h>

char* powersGame(int n) 
{
    /*
     * Write your code here.
     */
  int result = 0;
  int k = 0;

	int size = (int)pow(2,n);
  int arr[size] ;
	memset(arr, 0, size);
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < pow(2, i-1); j++)
    {
      for(int op = 0; op < 2; op++)
      {
        if (op == 0)
          arr[j+k] += +(pow(2, i));
        else
          arr[j+k+1] += -(pow(2, i));
      }
      k++;
    }
  }
  
  for(int i =0; i < pow(2, n); i++)
  {
    printf("arr[%d]=%d ", i, arr[i]);
  }
  
  if((result % 17) == 0)
    return "First";
  else
    return "Second";
}

int main(int argc, char **argv)
{

	printf("\n%s\n", powersGame(6));

	return 0;
}

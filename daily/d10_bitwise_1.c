/*
 * Day: 10
 * Date: 16/07/23
 * Problem: Bitwise operators tests.
 * Approach: Will be in the question.
 * Files: d10_bitwise_1.c
 */

/*
 * Different bitwise operators tests. 
 */

#include <stdio.h>

// Just emulate main()
void numToBinary()
{
  int num = 0, i = 0;

  printf("Enter a num: ");
  scanf("%d", &num);

  i = sizeof(num) * 8;
  --i;

  
  while(i >= 0)
  {
    printf("%d", (num & (1 << i)) ? 1 : 0);
    --i;
  }

  /*
  for(i = 7; i >= 0; i--)
    printf("%d", ((num >> i)  & 1 ) ? 1 : 0);
  */
}

int main(int argc, char *argv[])
{
  // Function body

  numToBinary();

  printf("\nEnd of the program\n");

  return 0;
}

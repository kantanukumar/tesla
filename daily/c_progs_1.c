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
#include <string.h>
#include <stdlib.h>

// Just emulate main()
// This just displayes the number in binary equivalent.
// If we want to convert the number to binary, then we need
// to have an array, which stores the binary number as elements.
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

  printf("\n");

  /*
  for(i = 7; i >= 0; i--)
    printf("%d", ((num >> i)  & 1 ) ? 1 : 0);
  */
}


// Given a binary number, display its decimal equivalent.
// Let's take the binary as a string of chars.
void binaryToDecimal()
{
  char arr[64] = {'0'}; // Enough to hold a long long
  int len = 0, num = 0;

  printf("Enter a binary number: ");
  scanf("%s", arr);

  printf("Binary num=%s\n", arr);

  len = strlen(arr);

  for(int i = len-1, j = 1; i >= 0; i--, j *= 2)
  {
    if(arr[i] != '0')
      num += j;
  }

  printf("Number in decimal=%d\n", num);
}

int main(int argc, char *argv[])
{
  // Function body

  numToBinary();

  binaryToDecimal();

  printf("\nEnd of the program\n");

  return 0;
}

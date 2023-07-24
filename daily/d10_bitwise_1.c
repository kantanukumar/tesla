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

// Get the bit and displays in this function
// (num >> i) & 1 or num & ( 1 << i) ? 1 : 0
void getIthBit()
{
  printf("Gets ith bit\n");
  int i = 0, num = 0;
  printf("Input num: ");
  scanf("%d", &num);
  printf("Input bit to get: ");
  scanf("%d", &i);
  printf("%dth bit=%d\n", i, ((num >> i) & 1));
}

// Sets ith bit and displays in this function
// num |= 1 << i
void setIthBit()
{
  printf("Sets ith bit\n");
  int i = 0, num = 0;
  printf("Input num: ");
  scanf("%d", &num);
  printf("Input bit to set: ");
  scanf("%d", &i);
  num |= 1 << i;
  printf("num = %d, afer setting bit=%d\n", num, i);
}

// Clears ith bit and displays in this function
// num &= ~(1 << i)
void clearIthBit()
{
  printf("Clears a bit\n");
  int i = 0, num = 0;
  printf("Input num: ");
  scanf("%d", &num);
  printf("Input bit to clear: ");
  scanf("%d", &i);
  num &= ~(1 << i);
  printf("num = %d, afer clearing bit=%d\n", num, i);
}

// Updates ith bit and displays in this function
// Clears the bit, then sets the bit
void updateIthBit()
{
  printf("Updates a bit\n");
  int i = 0, v = 0, num = 0;
  printf("Input num: ");
  scanf("%d", &num);
  printf("Input bit to update: ");
  scanf("%d", &i);

  printf("Input value to update: ");
  scanf("%d", &v);

  num &= ~(1 << i); // Clears the bit
  num |= (v << i);  // Update with new bit value

  printf("num = %d, afer updating the bit=%d with val=%d\n", num, i, v);
}

void setBitRange()
{
  printf("Sets a range of bits\n");
  int i = 0, j = 0, v = 0, num = 0, mask = 0;
  printf("Input num(hex): ");
  scanf("%x", &num);
  printf("Input bit range to update: i and j: ");
  scanf("%d %d", &i, &j);

  printf("Input value to update(hex): ");
  scanf("%x", &v);

  // Create the mask, Ex: if it is 2-4, we need to get "11",
  // then invert it to get the "11111100"
  mask = ~((1 << (j-i+1)) - 1);

  // Clear the bit ranges
  num &= (mask << i);

  // set the bit range
  num |= v;

  printf("Num=%x after setting %x fro pos %d-%d\n", num, v, i, j);

}

// Just emulate main()
// This just displays the number in binary equivalent.
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

  // numToBinary();
  // binaryToDecimal();

  // getIthBit();
  // setIthBit();
  // clearIthBit();
  // updateIthBit();
  setBitRange();


  printf("\nEnd of the program\n");

  return 0;
}

/* 
 * Day: 13
 * Date: 20/07/23
 * Problem: Print sum of a big size array, using single thread.
 *  Compare the execution timing for the same, with multi threaded approach.
 * Approach:
 *  1. Create an array with size 1000000000 elements.
 *  2. Compute the sum
 * 
 * Files: d13_3_sum_in_array_no_threads.c
 *        d13_2_sum_in_array_threads.c
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#define ELEMENT_SIZE 1000000000
int arr[ELEMENT_SIZE];

int main(int argc, char argv[])
{
  // Function body
  volatile int i = 0;
  // Initialize the array
  while(i < ELEMENT_SIZE)
  {
    arr[i] = i+1;
    ++i;
  }

  long long int sum = 0;
  for(int i = 0; i < ELEMENT_SIZE; i++)
  {
    sum += arr[i];
  }

/*
  i = 0;
  printf("Array elements:\n");
  while(i < ELEMENT_SIZE)
  {
    printf("%d\n", arr[i++]);
  }
*/

  printf("Total sum=%lld\n", sum);

  return 0;
}
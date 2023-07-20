/* 
 * Day: 13
 * Date: 20/07/23
 * Problem: Print sum of a big size array, using multiple threads.
 *  Compare the execution timing for the same, with single threaded approach.
 * Approach:
 *  1. Create an array with size 1000000000 elements.
 *  2. Create two threads
 *  3. One to operate on start one on end
 *  4. Combine both the sums at end
 *
 * Files: d13_2_sum_in_array_threads.c
 *        d13_3_sum_in_array_no_threads.c
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#define ELEMENT_SIZE 1000000000
int arr[ELEMENT_SIZE];

void* computeSum(void *arg)
{
  int start = *((int*)arg);
  printf("Start=%d\n", start);

  long long int sum = 0;
  for(int i = 0; i < ELEMENT_SIZE/2; i++)
  {
    sum += arr[start+i];
  }

  printf("Tid=%llp, sum=%lld\n", pthread_self(), sum);
 
 *((long long int*)arg) = sum;
  
  return arg;
}

int main(int argc, char argv[])
{
  volatile int i = 0;
  while(i < ELEMENT_SIZE)
  {
    arr[i] = i+1;
    ++i;
  }

/*
  i = 0;
  printf("Array elements:\n");
  while(i < ELEMENT_SIZE)
  {
    printf("%d\n", arr[i++]);
  }
*/
  // Function body
  pthread_t tid1;
  pthread_t tid2;

  int *start1 = (int*) malloc(sizeof(int));
  int *start2 = (int*) malloc(sizeof(int));

  *start1 = 0;
  pthread_create(&tid1, NULL, computeSum, start1);

  *start2 = ELEMENT_SIZE/2;
  pthread_create(&tid2, NULL, computeSum, start2);

  long long int *sum1 = (long long int*)malloc(sizeof(long long int));
  long long int *sum2 = (long long int*)malloc(sizeof(long long int));

  pthread_join(tid1, &sum1);
  pthread_join(tid2, &sum2);

  printf("Total Sum=%lld\n", *sum1 + *sum2);

  return 0;
}


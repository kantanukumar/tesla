#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target);

int main(int argc, char **argv)
{
  int arr[] = { 3, 2, 4 };
  int size = sizeof(arr)/sizeof(int);
  int target = 6;
  int *ptr = NULL;

  ptr = twoSum(arr, size, target);

  if(ptr)
    free(ptr);

	return 0;
}

int* twoSum(int* nums, int numsSize, int target)
{

  int *arr = malloc(sizeof(int)*2);
  char found = 0;

  printf("numSize=%d\n", numsSize);

#if 0
  // Efficient in space, but not time
  for(int i=0; i < numsSize; i++)
  {
    for(int j=i+1; j < numsSize; j++)
    {
      if(nums[j] == target-nums[i])
      {
        arr[0] = i;
        arr[1] = j;
        break;
      }
    }
  }
#endif

#if 0
  // Time efficient
  for(int i=0; i < numsSize; i++)
  {
    if(!found)
    {
        int temp = nums[i];

        printf("i=%d nums[i]=%d\n", i, nums[i]);

        for(int j = i+1; j < numsSize; j++)
        {
          printf("i=%d j=%d nums[i]=%d\n", i, j, nums[j]);
          if(temp+nums[j] == target)
          {
            arr[0] = i;
            arr[1] = j;
            found = 1;
            break;
          }
        }
    }
  }
#endif

  printf("arr[0]=%d, arr[1]=%d\n", arr[0], arr[1]);
  return arr;
}

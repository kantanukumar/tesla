#include <stdio.h>

int main()
{


}


#if 0
  // Simple logic to just find an element in array and delete that element
  // Deleting the element means, we should shift all the elements after it
  // to the left. This is O(n) time complexity.

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int arr_len = sizeof(arr)/sizeof(arr[0]);

  int i = 0;
  
  for(i = 0; i < arr_len; i++)
  {
    printf("%d ", arr[i]);
  }

  i = 0;
  while(arr[i] != 5)
  {
    i++;
  }

  for(i; i < arr_len; i++)
  {
    arr[i] = arr[i+1];
  }
  
  for(i = 0; i < arr_len; i++)
  {
    printf("%d ", arr[i]);
  }
#endif

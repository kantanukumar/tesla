#include <stdio.h>

void sortBinary(char arr[], int size);

int main()
{
  char arr[] = {0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0};

  int size = sizeof(arr)/sizeof(arr[0]);

  sortBinary(arr, size);

#if 0
  // Bubble it up
  int arr[] = { 1, 3, 4, 7, 3 , 5, 4, 0 };

  int arr_size = sizeof(arr) / sizeof(arr[0]);

  int i = 0;


  while(arr[i] != '\0')
    printf("%d\n", arr[i++]);

  for(i = 0; i < arr_size; i++)
  {
    for(int j = 0; j < arr_size - i; j++)
    {
      if(arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("\n");

  i = 0;
  while(i < arr_size)
    printf("%d\n", arr[i++]);
#endif

  return 0;
}

void sortBinary(char arr[], int size)
{
  if(arr)
  {
    //int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i = 0;

    for(i = 0; i < size; i++)
     printf("%d ", arr[i]);
    printf("\n");

    int start = 0;
    int end   = size - 1;

    while(start != end)
    {
      if(arr[start] < 1)
       start++;
      else if(arr[end] > 0)
       end--;
      else
      { // swap
        arr[end] = arr[start];
        arr[start] = 0;

        start++;
        end--;
      }

    }
    for(i = 0; i < size; i++)
     printf("%d ", arr[i]);

    printf("\n");
  }

}

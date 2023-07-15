#include <stdio.h>

#if 0
int f(int val){}

int main(int argc, char *argv[])
{
  f(5);

  return 0;
}

#endif

#include<stdio.h>

int main()
{
    // Pointer to an integer
    int *p;

    // Pointer to an array of 5 integers
    int (*ptr)[5];
    int arr[5];

    // Points to 0th element of the arr.
    p = arr;

    // Points to the whole array arr.
    ptr = arr;

    printf("p = %p, ptr = %p\n", p, ptr);

    p++;
    ptr++;

    printf("p = %p, ptr = %p\n", p, ptr);

    return 0;
}



#if 0

int main()
{
  const int i = 10;

  char *pArr = "1234567890";

  char *p = pArr;

  printf("*p=%d\n", *p);
//  i = 5;

  int *ptr = &i;

  *ptr = 6;

  printf("i = %d\n", i);

}

#endif

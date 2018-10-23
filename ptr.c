#include <stdio.h>

  int c = 20;
void func(int *ptr)
{
  printf("Func=%s\n", __func__);
  printf("*ptr=%p ptr=%p\n", *ptr, ptr);

  printf("change what ptr is holding...\n");
  ptr = &c;
  printf("ptr=%p\n", ptr);

}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};

  int str[20];

  printf("size without=%ld\n", (((int*)0)+1));

  printf("%d %d\n", sizeof(NULL), sizeof(""));

  int a, *ptr;

  ptr = arr;
  printf("*ptr = %d\n", *ptr);

  *ptr++;
  printf("*ptr++ = %d\n", *ptr++);

#if 0

  a = 5;
  ptr = &a;

  printf("*ptr=%d\n", *ptr);

  int b = 15;
  ptr = &b;

  printf("*ptr=%d\n", *ptr);
  
  int **pptr = NULL;
  pptr = &ptr;

  printf("*pptr=%p\n", *pptr);
  printf("**pptr=%p\n", **pptr);

  func(ptr);

  printf("After func, ptr=%p, *ptr=%d\n");
#endif

//  str = a; // Not allowed

#if 0
  int *ptr = NULL;
  ptr = a;

  printf("ptr=%p\n", ptr);
  printf("*ptr++=%p %p %p %p\n", *ptr++, *ptr, ptr, a[0]);
  printf("++*ptr=%p %p %p %p\n", ++*ptr, *ptr, ptr, a[(ptr-a)]);
  printf("++(*ptr)=%p %p %p %p\n", (*ptr)++, *ptr, ptr, a[0]);
  printf("*(ptr++)=%p %p %p %p\n", *++ptr, *ptr, ptr, a[0]);
#endif

}

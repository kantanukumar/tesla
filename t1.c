#include <stdio.h>

// This is a comment
//
int main()
{
  int c =0;
  volatile int a = 0;

  //c = ++a + ++a + ++a;

  volatile int i = 0;

  while(i++)
  {
   printf("print\n");
   ;
  }

//  printf("c=%d a=%d \n", c, a);

}

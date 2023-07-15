int main()
{

 char *s[] = {"abcd", "zyx", "12345"};

 char **p;

 p = s;

 printf("*p = %s\n", *p);
 printf("++*p = %s\n", ++*p);


 printf("*p++ = %s\n", *p++);

 int g;
 long int *x = &g; g = 0xffffffffff;
 printf("*x = %d\n", *x);
 /* // seg fault
  int i, *p, **q;

  i = 5;

  p = &i;

  q = p;

  printf("*p=%d, **=%d\n", *p, **q);
*/


 /*
  char *p = "lakshya";
  char *p1;

  p1 = (char*)malloc(10);

  while(*p1++ = *p++);

  printf("p1=%s\n", p1);
  */

 return 0;
}

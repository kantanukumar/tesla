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

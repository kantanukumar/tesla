#include <stdio.h>

int main()
{
  char arr[26];
  bzero(arr, 26);

  char lru[5];
  char ch='\0';

#if 0
  do
  {
    printf("char is '%c'\n", ch);
  } while('\EOF' != (ch = getchar()));
#endif

  do
  {
    printf("Enter a char: ");
    scanf(" %c", &ch);
    printf("char = '%c'\n", ch);
  }while(ch != 'q');

}

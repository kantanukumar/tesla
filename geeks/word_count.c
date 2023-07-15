#include <stdio.h>

int main(int argc, char **argv)
{
  char str[] = "This is a big  sentence,  containing 8 words";
  int i = 0, wc = 0;

  while(str[i])
  {
    if((str[i] == ' ' && str[i+1] != ' ') || (str[i] == ','))
    {
      wc++;
    }
    i++;
  }

  printf("sizeof(str)=%d, strlen(str)=%d\n", sizeof(str), strlen(str));

  printf("Word counts in str = %d\n", wc);

	return 0;
}

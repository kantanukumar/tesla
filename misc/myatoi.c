#include <stdio.h>

void myAtoi(char *str);

int main(int argc, char **argv)
{

  if(argc == 2)
   printf("Args %s, %s\n", argv[0], argv[1]);
  else
  {
   perror("Invalid arguments\n");
   return -1;
  }

  myAtoi(argv[1]);



	return 0;
}

void myAtoi(char *str)
{
  printf("Str = %s\n", str);


  // Validations
  if(str)
  {
    if(str[0]
  }
  return;
}

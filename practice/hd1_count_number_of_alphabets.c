#include <stdio.h>

int main(int argc, char **argv)
{
	char arr[100] = {0};
	char alph[26] = {0};

	printf("Enter a string: ");
	scanf("%s", arr);

	for(int i = 0; i < strlen(arr); i++)
  {
    alph[arr[i] - 'a']++;
  }

	for(int i = 0; i < 26; i++)
	{
    if(alph[i] > 0)
		  printf("%c = %d times\n", ('a'+i), alph[i]);
  }

	return 0;
}

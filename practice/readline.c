#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
char* readline();

int main()
{
    char* n_endptr;

		for(int i = 0; i < 10; i++)
		{
    char* n_str = readline();
		

		if(n_str)
		{
			printf("n_str = %s\n", n_str);
		}
		}
//    int n = strtol(n_str, &n_endptr, 10);

    //if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true)
    {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {return NULL; break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
				{ break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n')
		{
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

#endif

char* readline(void);

int main(int argc, char **argv)
{
	printf("****** READLINES FROM STDIN ******\n");

	for(int j = 0; j < 10; j++)
 	{
    char *n_str = NULL;
    char *n_endptr =  NULL;
    n_str = readline();
    
		if(n_str)
		{
	  	int n = 0;
  
	  	if(strlen(n_str) == 1)
  		{
				continue;
    		 n = strtol(n_str, &n_endptr, 10);
  		}

  		for(int i = 0; i < strlen(n_str); i=i+2)
  		{
   	 		if(n_str[i])
      		printf("%c", n_str[i]);
  		}

	  	printf(" ");

  		for(int i = 1; i < strlen(n_str); i=i+2)
  		{
    		if(n_str[i])
      		printf("%c", n_str[i]);
  		}
		}
		else
			break;
 	}
    return 0;
}

char* readline(void)
{
	char* line = NULL;
	char* data = NULL;

	data = malloc(1024);

	line = fgets(data, 1024, stdin);

	if(!line || (data[0] == '\n'))
	{
		printf("return null\n");
		return NULL;
  }

	if(data[strlen(data) - 1] == '\n')
		data[strlen(data) - 1] = '\0';

	return data;
}

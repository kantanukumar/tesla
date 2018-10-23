#include <stdio.h>


/*
 * 2. printf and scanf returns 
 *  
 * Number of characters printed to stdout
 *
 */
main()
{
	int ret = 0;
  ret = printf("%d");
	printf("\nret = %d\n", ret);

	gets();

}






/*
 * 1. prints garbage, if no arguments provided to printf 
 *  
 * Compiler issues a warning
 *
 *
main()
{
	printf("%d");
}

 */

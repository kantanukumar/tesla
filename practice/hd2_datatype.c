#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 4;
	double d = 4.0;
	char s[] = "HackerRank ";
	char str[200] = {0};

// Declare second integer, double, and String variables.
    int iSecond = 0;
    double dSecond = 0.0;
    char sSecond[200] = {'\0'};

    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.

   // printf("Enter an integer: ");
    scanf("%d", &iSecond);

   // printf("Enter a double: ");
    scanf("%lf\n", &dSecond);

    scanf("%[^\n]s", sSecond);
    //fgets(sSecond, 200, stdin);

    // Print the sum of both integer variables on a new line.
    printf("%d", i+iSecond);
    printf("\n%2.1lf", d+dSecond);
    // Print the sum of the double variables on a new line.
    printf("\n%s%s", s, sSecond);
    


#if 0
	printf("Enter a string: ");

	//scanf("%s", str);
//	scanf("%[^\n]s", str);
  fgets(str, 200, stdin);

	printf("Input string:%s\n", str);
#endif

	return 0;
}

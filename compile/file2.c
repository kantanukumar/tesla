/*
    Date: 27/07/23
    Problem: Create library.
    Approach: Create static and dynacmic libraries.
    Files: file1.c file2.c main.c
    Below function will be part of a library and intented to be called by main().
*/

void calculate()
{
    int num1, num2;
    num1 = num2 = 0;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Sum of %d and %d = %d\n", num1, num2, sum(num1, num2));
    printf("Multipication of %d and %d = %d\n", num1, num2, multiply(num1, num2));
}

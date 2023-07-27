/*
    Date: 27/07/23
    Problem: Create library.
    Approach: Create static and dynacmic libraries.
    Files: file1.c file2.c main.c
    Below function will call the library.
*/

void calculate(void);

int main()
{
  printf("Call calculation function\n");
  calculate();

  return 0;
}
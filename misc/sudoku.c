#include <stdio.h>

int main(int argc, char **argv)
{
  // keep it simple
  int arr[4][4] = {{0, 2, 3, 4}, {4, 3, 2, 1}, {2, 1, 4, 3}, {3, 4, 1, 2}};
  int r = 0, c = 0;

  printf("Current sudoku:\n");
  for(r = 0; r < 4; r++)
  {
    for(c = 0; c < 4; c++)
      printf("%d|", arr[r][c]);

    printf("\n");
  }

  printf("\n");

  int r_sum = 0;

  // Find out the positions:
  for(r = 0; r < 4; r++)
  {
    for(c = 0; c < 4; c++)
      if(!arr[r][c])
        r

    c_sum !=
  }

	return 0;
}

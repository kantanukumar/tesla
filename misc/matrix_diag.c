#include <stdio.h>

int main(int argc, char **argv)
{
	int mat[5][5] = {{1, 2, 3, 4, 6},
                   {5, 4, 3, 5, 7}, 
                   {6, 5, 9, 8, 9},
                   {9, 8, 7, 6, 1},
                   {1, 8, 3, 6, 2}
                  };

	int row=0, col=0;

#if 1 
	for(row = 0; row < 5; row++)
	{
		for(col = 0; col < 5; col++)
		{
			printf("%d ", mat[row][col]);
		}
		printf("\n");
	}
	printf("\n\n");
#endif

	// Diag print - upside  to down


/*

1 
5 2 
6 4 3 
9 5 3 4 
1 8 9 5 6 
8 7 8 7 
3 6 9 
6 1 
2 

*/



	int max_row = 5;
	int max_col = 5;
  int r_count = 0;

#if 1

	for(r_count = 0; r_count < max_row; r_count++)
	{
		for(row = r_count, col = 0; (row >= 0) && (col <= r_count); row--, col++)
		{
			  printf("%d ", mat[row][col]);
    }
		printf("\n");
	}

	for(r_count = 0; r_count < max_row-1; r_count++)
	{
		for(row = max_row-1, col = r_count+1; (row >=0) && (col < max_row); row--, col++)
		{
			  printf("%d ", mat[row][col]);
		}
		printf("\n");
	}

#if 1 
	printf("\n\n");
	for(r_count = 0; r_count < max_row; r_count++)
	{
		for(col = r_count, row = 0; (col >= 0) && (row <= r_count); row++, col--)
		{
			  printf("%d ", mat[row][col]);
    }
		printf("\n");
	}
#endif
#endif

	return 0;
}

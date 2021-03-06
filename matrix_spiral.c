#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5
#define MAX_COL 5

// Fills a m*n matrix with sequencial values
/*
	int mat[MAX_ROW][MAX_COL] = {
                   {a, b, c, d, e},
                   {f, g, h, i, j}, 
                   {k, l, m, n, o},
                   {p, q, r, s, t},
                   {u, v, w, x, y}
                  };
*/

int fillMatrix(int m, int n, int *mat[] )
{
	int i = 0x61; // Start with character 'a'
	int r = 0;
	int c = 0;

	if(mat)
	{
		for(r = 0; r < m; r++)
		{
			for(c = 0; c < n; c++)
			{
				mat[r][c] = i++;
			}
		}
  }
	else
	{
		perror("mat NULL\n");
		return 1;
	}
	return 0;
}

// Prints an m*n matrix
int printMatrix(int m, int n, int **mat)
{
	int i = 0;
	int r = 0;
	int c = 0;

	if(mat)
	{
		printf("Print %d*%d matrix:\n", m, n);

		for(r = 0; r < m; r++)
		{
			for(c = 0; c < n; c++)
			{
				printf("%c ", mat[r][c]);
			}
			printf("\n");
		}
	}
	else
	{
		perror("mat NULL\n");
		return 1;
	}

	printf("\n");
	return 0;
}

// Print a matrix spiral...

/*
    a b c d e j o t y x w v u p k f g h i n s r q l m
 */

void printSpiral(int **mat)
{
	if(mat)
	{
		printf("Print matrix spiral...\n");
	}
	else
		return;

	int row=0, col=0;

	int first_row = 0;
	int first_col = 0;
	int last_row = MAX_ROW - 1;
	int last_col = MAX_COL - 1;

 while((last_row >= first_row) && (last_col >= first_col))
 {
	for(col = first_col; col <= last_col; col++)
	{
		printf("%c ", mat[first_row][col]);
	}
	first_row++;

	for(row = first_row; row <= last_row; row++)
	{
		printf("%c ", mat[row][last_col]);
	}
  last_col--;

	for(col = last_col; col >= first_col; col--)
	{
		printf("%c ", mat[last_row][col]);
	}
	last_row--;

	for(row = last_row; row >= first_row; row--)
	{
		printf("%c ", mat[row][first_col]);
	}
	first_col++;
 }

	return;
}

int main(int argc, char **argv)
{
	int **mat = NULL;

	mat = (int**) malloc(sizeof(int*) * MAX_ROW );

	for(int i = 0; i < MAX_ROW; i++)
	{
		mat[i] = (int*) malloc(sizeof(int) * MAX_COL);
	}

	if(fillMatrix(MAX_ROW, MAX_COL, mat) == 0)
	{
		printMatrix(MAX_ROW, MAX_COL, mat);
	}
	else
	{
		perror("Allocation Failure\n");
		return 1;
	}

	printSpiral(mat);

	printf("\n");

	return 0;
}

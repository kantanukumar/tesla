#include <stdio.h>

int main(int argc, char **argv)
{
	int arr[]= {1, 4, 20, 3, 10, 5};

	int sum = 0;

	printf("Enter sum:");
	scanf("%d", &sum);

	int arr_size = sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i < arr_size; i++)
	{
		int comp_sum = 0;

		if(arr[i] <= sum)
		{
			for(int j=i; j< arr_size; j++)
			{
				comp_sum = arr[j] + comp_sum;
				if(comp_sum == sum)
				{
					printf("Found sum = %d, between %d and %d\n", sum, i, j);
					break;
				}
			}
		}
	}

	return 0;
}

#include <stdio.h>

int main(int argc, char **argv)
{

#if 0
	/* 2D array */
	char a[4][10] = {"India", "is", "my", "country"};

//	int arr_size = sizeof(a)/sizeof(a[]);

//	printf("arr_size = %d\n", arr_size);
	int i =0;
	char temp[10];
	int size = 4;

	for(i = 0; i < size/2; i++)
	{
		printf("a[%d]=%s\n", i, a[i]);
		memset(temp, '\0', 10);
		strcpy(temp, a[i]);
		strcpy(a[i], a[size - i -1]);
		strcpy(a[size - i -1], temp);
	}

	for(i = 0; i < size; i++)
	{
		printf("a[%d]=%s\n", i, a[i]);
	}
#endif

#if 0
	//1D array
	int a[] = {1, 2, 3, 4, 5, 6, 7};

	int i = 0;
	int arr_size = sizeof(a)/sizeof(int);

	printf("arr_size = %d\n", arr_size);

	for(i=0; i < arr_size/2; i++)
	{
		int temp = a[i];
		a[i] = a[arr_size - i - 1];
		a[arr_size - i - 1] = temp;
	}

	for(i=0; i < arr_size; i++)
		printf("a[%d] = %d\n", i, a[i]);
#endif

	// 1D array with pointer
	char name[] = "kantanu";

	char *ptr = name;

	for(int i = 0; i < (sizeof(name)/sizeof(name[0])/2 ); i++)
	{
		char temp = ptr[i];
		ptr[i] = ptr[sizeof(name)/sizeof(name[0]) - i - 2];
		ptr[sizeof(name)/sizeof(name[0]) - i -2] = temp;
	}

	printf("ptr='%s'\n", ptr);


	// Make it to pointer ?????
	//
	return 0;
}

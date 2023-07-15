#include <stdio.h>

void print_array(int *arr, int len)
{
    if(len <= 0)
        perror("Wrong length\n");

    int i = 0;

    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rotate_array(int *arr, int len, int rotate)
{

}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int len = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, len);

    int temp = 0;
    int rotate = 3;
    int i = 0;

    // Rotate left
    printf("Rotate array left by %d times\n", rotate);
    while(rotate--)
    {
        temp = arr[0];
        for(i = 0; i < len-1; i++)
        {
            arr[i] = arr[i+1];   
        }
        arr[len-1] = temp;
        print_array(arr, len);
    }
    
    rotate = 3;
    // Rotate right
    printf("Rotate array right by %d times\n", rotate);
    while(rotate--)
    {
        temp = arr[len-1];
        for(int i = len-1; i > 0; i--)
        {
            arr[i] = arr[i-1];
        }          
        arr[0] = temp;
        print_array(arr, len);
    }    
}
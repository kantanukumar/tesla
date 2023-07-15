/*
    This was written to compare the map-reduce algo with single threaded algo
    Unfortunately this is not complete yet, I have to complete it someday.
    TODO: Complete the prog.
*/

#include <stdio.h>
#include <pthread.h>

#define MAX_LEN 1000000 

int main(int argc, char* argv[])
{
    int arr[MAX_LEN] = {1};
    int sum = 0;
    int i = MAX_LEN;

    while(i--)
    {
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);

    return 0;
}
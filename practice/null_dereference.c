#include <stdio.h>

int main()
{
    int x = 5;

    int *px = &x;
    px = 0;

    printf("Cnt=%d\n", *px);
}
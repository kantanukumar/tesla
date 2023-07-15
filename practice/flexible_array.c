#include <stdio.h>

union U
{
    char buf[100];
};

struct ABC
{
    /*
    char c1;
    char c2;
    double d1;
    union U u1;
    */
    int i1;
};

int main()
{
    struct ABC abc;
    printf("sizeof ABC: %d\n", sizeof(abc));
}
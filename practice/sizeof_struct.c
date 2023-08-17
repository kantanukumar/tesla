/*
 * Day: N/A
 * Date: 17/08/23
 *
 * Problem: Calcuclate sizeof a structure, without sizeof operator.
 *              i.e. Create a MACRO for to calculate struct size
 *  One of the IPC mechanism.
 *
 * Approach:
 *  A1. Just call the sizeof() from MACRO
 *  A2. Use pointer arithmatic to calculate the size.
 */

#include <stdio.h>

struct myStruct
{
    int a;
    int b;
    char ch;
};

// A1
// #define xsizeof(type) (sizeof(type))
// printf("Sizeof myStruct=%d\n", xsizeof(struct myStruct));

// A2
#define xsizeof(type) ((char*)(&type + 1) - (char*)(&type))

int main()
{
    struct myStruct s;

    printf("Sizeof myStruct=%ld\n", xsizeof(s));

    return 0;
}
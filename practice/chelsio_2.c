#include <stdio.h>

int main()
{
#if 0
// Q - 4
// Define a linked list node, allocate contiguous memory of 10 nodes.
// Assign 5, to the 5th node.

    struct node
    {
        int data;
        struct node *next;
    }*np=NULL;

    np = (struct node*)malloc(sizeof(struct node) * 10);

    np[4].data = 5;

    printf("np[4]=%d\n", np[4].data);

    char *cp = np;

    for(int i = 0; i < (sizeof(struct node) * 10); i++)
    {
        printf("%2x ", *(cp+i));
    }
    printf("\n");
#endif

#if 0
// Q - 3
// What will be the output of this ?
    int *ptr = 100;
    ptr++;

    printf("%ld\n", ptr);
    // Ptr will print 104, as it goes to the next integer location
    // by pointer arithmatic. But it will seg fault, if we try dereferencing it
#endif


#if 0
Q - 2
    if( -1 < sizeof(int) )  
        // <--- The comparisn is with signed integer(-1) and unsigned int
        // if( -1 < sizeof(int) ) <--- The comparisn is with signed integers
        printf(" -1 is less\n");
#endif

#if 1
    // This stops, when i becomes zero, because of overflow.
//  int i = 0;
//  while(i++)
//      printf("%d ", i);
   
   /*
    // This is the overflow condition
    long int i = 0xFFFFFFFF;
    printf("%lx ", i);
    ++i;
    printf("%lx \n", i);

    */
#endif

    return 0;
}

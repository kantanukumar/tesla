/*
    This learning from Udemy - Vignesh
*/


#include <stdio.h>

// B[i][j] = *(B[i]+j) = *(*(B+i)+j)


int main()
{
    // favFr is an array of pointers,
    // favFr is an array, where each element is pointing to a string
    // In the below case, *favFr[] = *favFr[3]
    // Array mango jackfruit and "banana" will not be in contiguous address,
    // but favFr is guarranteed to have the contiguous memory

    //If this was char (*favFr)[] ---> This is pointer to an array
    char *favFr[] = {"mango", "jackfruit", "banana"};

    printf("sizeof favFr=%d\n", sizeof(favFr));

    printf("%s\n", *favFr); 
    printf("%s\n", *(favFr+1));
    printf("%s\n", *favFr+1);
    printf("%s\n", *(favFr+1)+3);
    printf("%d\n", *(favFr+1));
    printf("%c\n", **(favFr+1));
    printf("%c\n", *(*(favFr+2)+4));
    printf("%c\n", favFr[2][4]);
    printf("%s\n", &favFr[2][3]);
    printf("%c\n", **favFr);
    printf("%s\n", *favFr);
    printf("%s\n", favFr[2]+2);
    printf("%c\n", favFr[2]+3);
    


/*
    int A[ ] = {10, 11, 15, 18, 45};

    int *p = A;

    printf("p = %p\n", p);
*/
}




#if 0

/*
Learnings
*/

    void *ptr = NULL;

    int a = 10;

    ptr = &a;

    printf("*ptr=%d\n", *(int*)ptr);

#endif
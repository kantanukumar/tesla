#include <stdio.h>

int main()
{
    unsigned int num = 0;
    int i = 0;

    printf("Give the number of letters: ");
   
    scanf("%d", &num);

    printf("Give %d letters, to find all the possible words:\n", num);

    char a[num];

    for(i = 0; i < num; i++)
    {
        scanf(" %c", &a[i]);
    }
    
    a[num] = '\0'; //end the string here

    printf("Chars are: ");
    for(i = 0; i < num; i++)
        printf("'%c' ", a[i]);

    printf("\n");

    // Logic to get the substrings
    // Number of substrings are num! i.e. num * (num-1)!
   
   /* 
    unsigned int fact = 1;
    printf("%d!=", num);
    while(num)
    {
        fact = fact * num;
        num--;
    }
    printf("%u\n", fact);
   */

    // Permutation = All combinations nPr
    // Combnations = Unique combinations
    // 1 letter words
    for(i=0; i<num; i++)
           printf("%c", a[i]);
    printf("\n");

    // a b c

    int k = 0;
    // 2 letter words
    for(k = 0; k < num; k++)
    {
        for(i=0;i < num; i++)
        {
            printf("%c%c\n", a[k], a[i]);
        }
    }

    return 0;
}

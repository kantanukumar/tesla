#include <stdio.h>

int main(int argc, char *argv[])
{
    char arr[26] = {0}; // Array to hold all elements
    int idx = 0;

    if(argc == 2)
    {
        char *p = (char*)argv[1];

        while(*p)
        {
            if(*p >= 'a' && *p <= 'z')
            {
                idx = *p - 'a';
                arr[idx]++;
            }
            else
            {
                printf("%d is not an alphabet\n", *p);
                continue;
            }
            p++;
        }
    }

    printf("Counts of alphabets in the string \"%s\"\n", argv[1]);
    for(idx = 0; idx < 26; idx++)
    {
        printf("%c %d\n", idx+'a', arr[idx]);
    }
}
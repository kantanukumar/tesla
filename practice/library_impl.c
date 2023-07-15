/*
    I am really disappointed and ashamed by my programming skills
    since I can not do library function implementations.

    I will do each and every libray calls one by one here.

    27/06/2023: strcmp() - IBM(2)
    
*/

#include <stdio.h>
#include <string.h>

// Does a strcmp()
int myStrCmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int match = 0;

    if(len_s1 < len_s2)
        return -1;

    while(s1[i])
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
            // Reached end of needle
            if(j == len_s2)
            {
                // match = 1;
                return 0;
            }
        }
        else
        {
            i++;
            // Lets start from the beginning of S2
            j = 0;
            // match = 0;
        }
    }
    return s1[i-1] - s2[j-1];
}

// Does a strstr()
void * myStrstr(char *s1, char *s2)
{
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    int i = 0;
    int j = 0;

    if (len_s1 < len_s2)
        return NULL;

    for(i=0; i < len_s1; i++)
    {
        if(s1[i] == s2[j])
        {
            j++;

            if(j == len_s2)
            {               
                return &s1[i];
            }
        }
        else
            // Lets start from the beginning of S2
            j = 0;      
    }

    return NULL;       
}


int main()
{
    // printf("Match = %s\n", myStrCmp("Kantanu", "Kanta")? "fail" : "success");
    printf("Match at %p\n", myStrstr("Kantanu", "ant"));
    #if 0
    char arr[18] = "Kantanu";
    char *ptr = malloc(15);
    memcpy(ptr, "kantanu", 8);

    int len_a = sizeof(arr);
    for(int i = 0; i < sizeof(arr); i++)
        printf("%c", arr[i]);

    int i = 0;
    int match = 0;
    int len = strlen(arr);

    while(arr[i] && ptr[i])
    {
        if(arr[i] == ptr[i])
        {
            continue;
        }
        else
        {
            match = 0;
        }
        i++;
    }
    #endif
}
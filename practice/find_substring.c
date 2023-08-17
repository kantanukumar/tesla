/*
 * Day: N/A
 * Date: 17/08/23
 *
 * Problem: Find string in a subsstring.
 *
 * Approach:
 *  Take an array, find substring in that array.
 */

#include <stdio.h>
#include <string.h>

// Return true if found, false otherwise
int findSubStr(char *arr, char *sub)
{
    int arrLen = strlen(arr);
    int subLen = strlen(sub);
    int found = 0;

    if(subLen > arrLen || !subLen || !arrLen)
        return 0;
    else
    {
        int i = 0;
        int j = 0;

        while (j < arrLen)
        {
            i = 0;
            while (i < subLen)
            {
                if(sub[i] == arr[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                    break;
                }
            }

            // We reached end of the substring
            if(i == subLen)
                found++;
        }
    }

    printf("Found substring '%s' in '%s' %d times\n", sub, arr, found);

    return (found ? 1 : 0);
}

int main()
{
    char arr[128]="Hello Hi Hello HiHelloHelloHell";
    char sub[128]="Hello";

    findSubStr(arr, sub);

    return 0;
}
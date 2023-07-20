/* 
 * Day: 13
 * Date: 20/07/23
 * Problem: How can you print marked "line 11" irrespctive of check ?
 *  This was part of some interview for someone.
 * Approach:
 *  1. as "check" is uninitialized, if anytime check gets value other than zero
 *      it will return a value, which makes to print "line 11"
 *  2. We can do gdb, break at check_password(), then return 1,
 *      which will force the if condition to true.
 * Files: d13_force_check_if_true.c
 */

#include <stdio.h>
#include <string.h>

int check_password()
{
    char passwd[20];
    scanf("%s", passwd);
    int check;

    if (strcmp(passwd, "xxxx") == 0) 
    {
        check = 1;
    }
    return check;
}

int main()
{
    if (check_password()) 
    {
        printf("password is valid");  // <--- line 11
    }
    else 
    {
        printf("Invalid");
    }
}

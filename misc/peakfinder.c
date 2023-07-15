#include <stdio.h>

int main()
{
    int a[] = {1, 2, 4, 2, 0, 1, 2};
    int n = sizeof(a)/sizeof(int);
    int cur_peak, last_peak, cur_pos, last_pos;
    int i = 1;
    cur_peak = last_peak = 0;

    for(i = 1; i < n-1; i++)
    {
        // you will find a peak by comparing left and right 
        if(( a[i] >= a[i-1] ) && ( a[i] >= a[i+1] ))
        {
            cur_peak = a[i];
            cur_pos  = i;
        }
        else
        {
            cur_peak = a[i+1];
            cur_pos  = i+1;
        }

        if(cur_peak > last_peak)
        {
            last_peak = cur_peak;
            last_pos  = cur_pos;
        }
    }

    printf("peak is=%d and position is=%d\n", last_peak, last_pos);
    return 0;
}

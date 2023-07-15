
// Below pattern should be printed
/*
 *
4 4 4 4 4 4 4  
4 3 3 3 3 3 4   
4 3 2 2 2 3 4   
4 3 2 1 2 3 4   
4 3 2 2 2 3 4   
4 3 3 3 3 3 4   
4 4 4 4 4 4 4

*/

int main()
{
  int n = 4;

  int length = n * 2;

    for (int row = 0; row <= length; row++) {
        if (row == n) {
            row ++;
            continue;
        };
        for (int col = 0; col <= length; col++) {
            if (col == n) {
                col +=1;
                continue;
            }
            int x = abs(n - row);
            int y = abs(n - col);
            printf("%d ", y > x ? y : x);
        }
        printf("\n");
    }
}

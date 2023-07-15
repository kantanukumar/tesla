#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
  int len = 5;
  int arr[len] = {0};
    char s1[10010], s2[10010];
    cin >> s1 >> s2;
    int a[26] = {0};
    for(int i = 0; i < strlen(s1); i++)
    {
        a[s1[i] - 'a']++;   
    }

    for(int i = 0; i < strlen(s2); i++)
    {
        a[s2[i] - 'a']--;
    }

    long long int ans = 0;
    for(int i = 0; i < 26; i++)
    {
        ans += a[i] ? 1 : 0;
    }
 
    cout << ans << endl;

		printf("a=%s\n", a);

	return 0;
}

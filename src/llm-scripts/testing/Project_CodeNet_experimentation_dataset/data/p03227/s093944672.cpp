#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    string s;
    cin >> s;
    if (s.length() == 2)
    {
        cout << s << endl;
    }
    else
    {
        cout << s[2] << s[1] << s[0] << endl;
    }
    return 0;
}
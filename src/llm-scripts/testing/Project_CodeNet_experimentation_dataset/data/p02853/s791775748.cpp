#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int x,y;
    cin >> x >> y;
    int ans = 0;
    if(x < 4)
    {
        ans += (4 - x) * 100000;
    }
    if(y < 4)
    {
        ans += (4 - y) * 100000;
    }
    if(x == 1 && y == 1)
    {
        ans += 400000;
    }
    cout << ans << "\n";
    return 0;
}
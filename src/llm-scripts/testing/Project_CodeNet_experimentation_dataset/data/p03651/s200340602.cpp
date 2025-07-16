#include <bits/stdc++.h>

///    ____ ____ ____ ____ ____
///   ||a |||t |||o |||d |||o ||
///   ||__|||__|||__|||__|||__||
///   |/__\|/__\|/__\|/__\|/__\|
///

using namespace std;

int gcd (int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int g = 0;
    int mi = INT_MAX, mx = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        g = gcd(g, val);
        mi = min(mi, val);
        mx = max(mx, val);
    }
    if(k % g == 0 && mi <= k && k <= mx)
        cout << "POSSIBLE\n";
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}

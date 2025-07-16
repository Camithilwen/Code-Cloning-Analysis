#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    long long m = x % 11LL;
    long long q = x / 11LL;
    long long ans = 0LL;

    if (1 < m)
        ans++;
    if (7 <= m)
        ans++;
    ans += 2 * q;
    if (m == 1)
        ans++;
    cout << ans << endl;
    return 0;
}
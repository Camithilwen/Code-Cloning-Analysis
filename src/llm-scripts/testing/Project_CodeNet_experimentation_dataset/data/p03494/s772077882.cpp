#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = INT_MAX;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int ans = inf, n, x, c;
    cin >> n;
    while (n--)
    {
        c = 0;
        cin >> x;
        while (x % 2 == 0)
            c++,
            x /= 2;
        ans = min(ans, c);
    }
    cout << ans;
    return 0;
}
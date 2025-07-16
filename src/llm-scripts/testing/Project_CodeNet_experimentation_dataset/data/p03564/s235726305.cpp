#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 1;
    rep(i, n)
    {
        ans = min(ans * 2, ans + k);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
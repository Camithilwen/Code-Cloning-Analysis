#include <bits/stdc++.h>
#define reps(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define rep(i, n) reps(i, 0, n - 1)
#define sper(i, s, n) for (int i = (s); i >= (int)(n); i--)
#define per(i, n) sper(i, n - 1, 0)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = n - k + 1;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
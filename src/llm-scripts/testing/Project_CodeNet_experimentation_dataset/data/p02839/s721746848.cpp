#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define int long long
using namespace std;

const int INF = 1e9;
int n, m;
int ans = INF;
int a[85][85], b[85][85];
bool f[85][85][52000];

void attempt(int i, int j, int diff)
{

    if (i == n && j == m)
    {
        ans = min(ans, abs(diff + a[i][j] - b[i][j]));
        ans = min(ans, abs(diff - a[i][j] + b[i][j]));
        return;
    }
    if (f[i][j][diff])
        return;
    f[i][j][diff] = 1;

    if (i < n){
        attempt(i+1, j, abs(diff + a[i][j] - b[i][j]));
        attempt(i+1, j, abs(diff - a[i][j] + b[i][j]));
    }
    if (j < m){
        attempt(i, j+1, abs(diff + a[i][j] - b[i][j]));
        attempt(i, j+1, abs(diff - a[i][j] + b[i][j]));
    }

}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("in.inp", "r", stdin);
//    freopen("out.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];

    attempt(1, 1, 0);
    cout << ans;
}

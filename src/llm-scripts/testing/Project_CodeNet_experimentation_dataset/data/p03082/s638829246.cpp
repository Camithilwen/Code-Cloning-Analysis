#include <bits/stdc++.h>
using namespace std;
#define INF_LL 1LL << 39
#define INF 100000000
#define MOD 1000000007LL
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define prique priority_queue
#define PI acos(-1)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vector<int>> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
struct edge {
    int to, cost;
};

ll dp[202][100010];

signed main() {
    int n, x;
    cin >> n >> x;
    vi s(n);
    rep(i, n) cin >> s[i];
    sort(all(s), greater<int>());
    dp[0][x] = 1;
    rep(i, n) REP(j, 0, x + 1) {
        dp[i + 1][j % s[i]] += dp[i][j];
        dp[i + 1][j] += dp[i][j] * (n - i - 1);
        dp[i + 1][j] %= MOD;
    }
    // rep(i, n + 1) {
    //     rep(j, x + 1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    ll res = 0;
    REP(i, 1, x + 1) {
        res += dp[n][i] * i;
        res %= MOD;
    }
    cout << res << endl;
}

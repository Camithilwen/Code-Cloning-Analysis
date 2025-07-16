#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
typedef long double ld;
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define in(a, x) for (int i = x; i < (a).size(); ++i) cin >> (a)[i]
#define out(a) for (auto qwe : a) cout << qwe << " "

const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 200000;

vii a;
vi p;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a.assign(n, vi(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    p.assign((1 << n), 0);

    for (int j = 0; j < (1 << n); ++j) {
        for (int i = 0; i < n; ++i) {
            if (!(j & (1 << i))) continue;
            for (int k = i + 1; k < n; ++k) {
                if (!(j & (1 << k))) continue;

                p[j] += a[i][k];
            }
        }
    }

    vi dp(1 << n, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int j = (1 << i); j <= (1 << (i + 1)) - 1; ++j) {
            for (int k = j; k; k = (k - 1) & j) {
                dp[j] = max(dp[j], p[k] + dp[j - k]);
            }
        }
    }

    cout << dp[(1 << n) - 1];
}
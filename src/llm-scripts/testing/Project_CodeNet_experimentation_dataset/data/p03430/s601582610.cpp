#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define sz(x)       int(x.size())
//#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = 302;
const int mod = 998244353;

string s;
int k, n, f[N][N][N];

int DP(int l, int r, int k) {
    if(f[l][r][k] != -1) return f[l][r][k];
    if(r < l) return f[l][r][k] = 0;
    if(l == r) return f[l][r][k] = 1;
    if(l + 1 == r) {
       if(k >= 1 || s[l] == s[r]) return f[l][r][k] = 2;
       return f[l][r][k] = 1;
    }
    int&res = f[l][r][k];
    res = max(DP(l + 1, r, k), DP(l, r - 1, k));
    if(s[l] == s[r]) {
        res = max(res, DP(l + 1, r - 1, k) + 2);
    } else if(k >= 1) {
        res = max(res, DP(l + 1, r - 1, k - 1) + 2);
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> s >> k; n = sz(s);
    s = ' ' + s;
    memset(&f, -1, sizeof f);
    cout << DP(1, n, k);
}

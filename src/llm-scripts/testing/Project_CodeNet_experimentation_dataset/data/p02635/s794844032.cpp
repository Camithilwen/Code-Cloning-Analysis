#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define emb emplace_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T> inline T range(T l, T r) {
    return uniform_int_distribution<T>(l, r)(rng);
}

inline void setin(string s) {
    freopen(s.c_str(), "r", stdin);
}

inline void setout(string s) {
    freopen(s.c_str(), "w", stdout);
}

template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}

template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 3e2 + 15;
int n, k;
string s;
int dp[2][N][N]; // dp[i][operation_applied][free_ones]
int a[N], p[N][N];

inline int add(int a, int b) {
    a += b;
    if(a >= mod)
        a -= mod;
    if(a < 0)
        a += mod;
    return a;
}

inline void add_t(int &a, int b) {
    a = add(a, b);
}

inline void construct() {
    int sz = 1;
    for(int i = 1; i <= n && s[i] == '1'; ++i)
        a[1] = i;
    for(int i = a[1] + 1; i <= n; ++i) {
        if(s[i] == '0') {
            if(i + 1 <= n && s[i + 1] == '0')
                a[++sz] = 0;
        }
        else {
            int j = i;
            while(j + 1 <= n && s[j + 1] == '1')
                ++j;
            a[++sz] = j - i + 1;
            i = j;
        }
    }
    n = sz;
}

inline void solve() {
    // dp[i][operation_applied][free_ones]
    dp[(n + 1) & 1][0][0] = 1;
    int sum = 0;
    for(int i = n; i >= 1; --i) {
        int bit = i & 1;
        memset(dp[bit], 0, sizeof(dp[bit]));
        for(int k = 0; k < N; ++k)
            for(int t = 0; t < N; ++t)
                p[k][t] = add(k && t ? p[k-1][t-1] : 0, dp[bit ^ 1][k][t]);

        for(int k = 0; k < N; ++k) {
            int val = 0;
            for(int t = N - 1; t >= 0; --t) {
                add_t(dp[bit][k][t], val);
                if(k - a[i] - 1 >= 0 && t - a[i] - 1 >= 0)
                    add_t(dp[bit][k][t], add(p[k][t], -p[k - a[i] - 1][t - a[i] - 1]));
                else
                    add_t(dp[bit][k][t], p[k][t]);
                add_t(val, dp[bit ^ 1][k][t]);
            }
        }
        sum += a[i];
    }
}

inline void output() {
    int ans = 0;
    for(int i = 0; i < min(N, k + 1); ++i)
        add_t(ans, dp[1][i][0]);
    cout << ans << endl;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // setin("input.txt");
    cin >> s >> k;
    n = s.size();
    s = '#' + s;
    construct();
    solve();
    output();
    return 0;
}
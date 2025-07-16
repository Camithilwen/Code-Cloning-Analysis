#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for(int i=a, loop=b; i<=loop; ++i)
#define REV(i, a, b) for(int i=a, loop=b; i>=loop; --i)
#define mize(a, b) a = min(a, b)
#define maxi(a, b) a = max(a, b)
#define shl(k) ((k) << 1)
using namespace std;

const int N = 2000 + 5, mod = 998244353;
int n, k;
int64_t C[N][N], G[N][N], F[N], P[N], d[N], tmp, res[N][2];

int main()
{
    ios::sync_with_stdio(); cin.tie(0);

    cin >> k >> n;

    int r = max(k, n);
    FOR(i, 0, r) C[i][0] = 1;
    FOR(i, 1, r) FOR(j, 1, i) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;

    G[0][1] = 1;
    FOR(i, 1, n) FOR(j, 1, k) G[i][j] = (G[i][j-1] + G[i-1][j]) % mod;
    G[0][0] = 1; G[0][1] = 0;
    FOR(i, 0, n) FOR(j, 1, k) G[i][j] = (G[i][j] + G[i][j-1]) % mod;

    for(int m=1; m+m<=k; ++m) FOR(i, 2, n) F[m] = (F[m] + C[i-1][m+m-1] * G[n-i][k-m-m] % mod) % mod;
    for(int m=1; m+m+1<=k; ++m) FOR(i, 2, n) {
        tmp = G[n-i][k-m-m-1];
        if (n-i-1 >= 0) tmp = tmp + G[n-i-1][k-m-m-1];
        P[m] = (P[m] + C[i-1][m+m-1] * tmp % mod) % mod;
    }

    int64_t ans; int m;
    FOR(i, 0, k) res[i][0] = res[i][1] = -1;
    FOR(t, 2, k+k) {
        m = 0; FOR(i, 1, k) if (1<=t-i && t-i<=k) m += 1;
        if (res[m/=2][t&1] != -1) {
            ans = res[m][t&1];
            goto REP;
        }

        if (t&1) {
            ans = G[n][k];
            REV(i, m, 1) {
                d[i] = F[i];
                FOR(j, i+1, m) d[i] = (d[i] - d[j] * C[m-i][j-i] % mod + mod) % mod;
            }
        } else {
            ans = (G[n][k-1] + G[n-1][k-1]) % mod;
            REV(i, m, 1) {
                d[i] = P[i];
                FOR(j, i+1, m) d[i] = (d[i] - d[j] * C[m-i][j-i] % mod + mod) % mod;
            }
        }

        FOR(i, 1, m) ans = (ans - d[i] * C[m][i] % mod + mod) % mod;
        res[m][t&1] = ans;
        REP: cout << ans << '\n';
    }
}

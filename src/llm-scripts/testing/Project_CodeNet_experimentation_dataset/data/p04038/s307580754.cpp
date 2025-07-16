#include "bits/stdc++.h"
#define MOD 1000000007
#define inf 0x3f3f3f3f3f3f3f3f
#define pi acos(-1.0)
#define ri register int
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
#define int long long
const int maxn = 2e3 + 10;
inline int Max(int a, int b) { return a > b ? a : b; }
inline int Min(int a, int b) { return a > b ? b : a; }
namespace FastIO {
inline int read()
{
    int f = 1, r = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    while (isdigit(c)) {
        r = 10 * r + c - '0';
        c = getchar();
    }
    return f * r;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
inline void writesp(int x) { write(x), putchar(' '); }
inline void writeln(int x) { write(x), puts(""); }
};
using namespace FastIO;
int N, K, dp[maxn][maxn], fac[maxn * maxn], ifac[maxn * maxn];
inline int exgcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int tmp = y;
    y = x - a / b * y;
    x = tmp;
    return d;
}
inline int inv(int a, int b)
{
    int x, y;
    exgcd(a, b, x, y);
    return (x + MOD) % MOD;
}
inline int C(int m, int n)
{
    int tmp = (fac[m] * ifac[n] % MOD) * ifac[m - n] % MOD;
    return tmp;
}
signed main()
{
    //freopen("C:\Users\hjw\Downloads\testdata (4).in", "r", stdin);
    N = read(), K = read();
    if (K == 1) {
        puts("1");
        return 0;
    }
    fac[0] = 1, ifac[0] = inv(1, MOD);
    for (ri i = 1; i <= N * K; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = inv(fac[i], MOD);
    }
    dp[0][1] = 1;
    for (ri j = 2; j <= N; ++j) {
        dp[0][j] = dp[0][j - 1] * C(j * (K - 1) - 1, K - 2) % MOD;
    }
    for (ri i = 1; i <= N; ++i) {
        for (ri j = i; j <= N; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] * C(j * (K - 1) + i - 1, K - 2)) % MOD;
        }
    }
    dp[N][N] = (dp[N][N] * fac[N] % MOD);
    writeln(dp[N][N]);
    return 0;
}
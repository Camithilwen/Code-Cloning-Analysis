#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 4e6 + 10, M = 2e3 + 10, MOD = 1e9 + 7;
int fac[N], inv[N], dp[M][M], ps[M][M];

int sum(int a, int b) {return (a + b) % MOD;}
int mul(int a, int b) {return (a * b) % MOD;}
int Pow(int a, int b)
{
    int res = 1;
    for (; b; b>>=1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int C(int n, int k)
{
    if (k < 0 || n < 0 || k > n) return 0;
    return mul(fac[n], mul(inv[k], inv[n - k]));
}


int32_t main()
{
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = Pow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
    int n, k; cin >> n >> k;
    if (k == 1) return cout << "1\n", 0;
    ps[1][1] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][1] = mul(ps[i - 1][1], C(i * k - 2, k - 2));
        for (int j = 2; j <= i; j++) {
            dp[i][j] = mul(ps[i - 1][j - 1], C(i * k - j - 1, k - 2));
        }
        for (int j = i; j >= 1; j--) ps[i][j] = sum(ps[i][j + 1], dp[i][j]);
    }
    cout << mul(ps[n][1], fac[n]) << "\n";
}

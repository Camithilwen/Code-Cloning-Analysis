#include <bits/stdc++.h>

using namespace std;
const int N = 4e3 + 5, MOD = 998244353;
int c[N][N], pw[N] = {1};

int mul() {return 1;}
template <typename Head, typename... Tail>
int mul(Head H, Tail... T) {return 1ll * mul(T...) * H % MOD;}
int sum() {return 0;}
template <typename Head, typename... Tail>
int sum(Head H, Tail... T) {return (mul(T...) + H) % MOD;}

int C(int n, int k) {
    if (k < 0 || n < 0 || n < k) return 0;
    return c[n][k];
}
int Solve(int n, int k, int m) {
    int r = k - m - m, res = 0;
    for (int i = 0; i <= m; i++) res = sum(res, mul(C(m, i), C(n + r - 1, n - i), pw[i]));
    return res;
}
int main() {
    c[0][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 0; j <= i; j++) c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    for (int i = 1; i < N; i++) pw[i] = mul(pw[i - 1], 2);
    int n, k; cin >> k >> n;
    for (int t = 2; t <= 2 * k; t++) {
        int m = 0;
        for (int i = 1; i <= k; i++) if (i <= t - i && t - i <= k) m++;
        if (t % 2 == 0) cout << sum(Solve(n, k - 1, m - 1), Solve(n - 1, k - 1, m - 1)) << "\n";
        else cout << Solve(n, k, m) << "\n";
    }

    return 0;
}

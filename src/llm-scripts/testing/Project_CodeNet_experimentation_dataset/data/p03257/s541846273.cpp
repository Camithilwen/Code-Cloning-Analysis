#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1001][1001], prm[2003];
int vis[100005], cnt;
void euler() {
    vis[1] = 1;
    for (int i = 2; i <= 10000; ++i) {
        if (!vis[i]) prm[++cnt] = i;
        for (int j = 1; j <= cnt && i * prm[j] <= 10000; ++j) {
            vis[i * prm[j]] = 1;
            if (!(i % prm[j])) break;
        }
    }
}

long long gcd(long long x, long long y) {
    while (y ^= x ^= y ^= x %= y) void();
    return x;
}

long long lcm(long long x, long long y) {
    if (!x || !y) return x + y;
    return x / gcd(x, y) * y;
}

int main() {
    scanf("%d", &n), euler();
    if (n == 2) return puts("4 7\n23 10\n"), 0;
    for (int i = 1; i <= n; ++i)
        for (int j = (i + 1 & 1) + 1; j <= n; j += 2)
            a[i][j] = prm[(i + j) / 2] * prm[n + (i - j) / 2 + (n + 1) / 2];
    for (int i = 1; i <= n; ++i)
        for (int j = (i & 1) + 1; j <= n; j += 2)
            a[i][j] = lcm(lcm(a[i - 1][j], a[i][j - 1]),
                          lcm(a[i][j + 1], a[i + 1][j])) +
                      1;
    for (int i = 1; i <= n; ++i, puts(""))
        for (int j = 1; j <= n; ++j) printf("%lld ", a[i][j]);
    return 0;
}
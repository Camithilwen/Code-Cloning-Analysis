// Crt. 2019-12-12  20:27:16
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;
typedef long long ll;

int n, m, now[N], ans[N], tmp[N];
ll x[N], y[N], z[N], K;

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", x + i), y[i] = x[i] - x[i - 1], now[i] = ans[i] = i;
    cin >> m >> K;

    for (int i = 1, t; i <= m; ++i)
        scanf("%d", &t), swap(now[t], now[t + 1]);

    while (K) {
        if (K & 1) {
            for (int i = 1; i <= n; ++i) tmp[i] = ans[now[i]];
            for (int i = 1; i <= n; ++i) ans[i] = tmp[i];
        }
        for (int i = 1; i <= n; ++i) tmp[i] = now[now[i]];
        for (int i = 1; i <= n; ++i) now[i] = tmp[i];
        K >>= 1;
    }

    for (int i = 1; i <= n; ++i)
        z[i] = y[ans[i]];

    for (int i = 1; i <= n; ++i)
        z[i] += z[i - 1], printf("%lld.0\n", z[i]);

    return 0;
}

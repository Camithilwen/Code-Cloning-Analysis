#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000 + 5;
const int kMod = 1'000'000'000 + 7;
int x[kN], y[kN];

int f(int *a, int n) {
    int sum = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = (a[i] % kMod + kMod) % kMod;
        int add = (1LL * a[i] * i + kMod - sum) % kMod;
        (res += add) %= kMod;
        (sum += a[i]) %= kMod;
    }
    return res;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &y[i]);
    int ans = 1LL * f(x, n) * f(y, m) % kMod;
    printf("%d\n", ans);
    return 0;
}

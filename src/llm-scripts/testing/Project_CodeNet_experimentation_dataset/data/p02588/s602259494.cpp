#include <bits/stdc++.h>
using namespace std;

const long long B = 1e9;

int n;
int f[25][25];

int calc(long long t) {
    int x = 0, y = 0;
    while (t % 2 == 0) { ++ x; t /= 2; }
    while (t % 5 == 0) { ++ y; t /= 5; }

    x = max(0, 18 - x);
    y = max(0, 18 - y);

    //assert(t == 1);

    int ans = 0;
    for (int i = x; i <= 20; ++i)
        for (int j = y; j <= 20; ++j) ans += f[i][j];
    return ans;
}

void inc(long long t) {
    int x = 0, y = 0;
    while (t % 2 == 0) { ++ x; t /= 2; }
    while (t % 5 == 0) { ++ y; t /= 5; }

    x = min(x, 18);
    y = min(y, 18);

    ++ f[x][y];
}

int main() {
#ifdef Wearry
    freopen("in", "r", stdin);
#endif

    long long ans = 0;
    scanf("%d", &n);
    while (n--) {
        double a;
        scanf("%lf", &a);

        long long temp = (long long) round(a * B);
        ans += calc(temp);
        inc(temp);
    }
    printf("%lld\n", ans);

    return 0;
}

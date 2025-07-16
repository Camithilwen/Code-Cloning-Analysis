#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

LL a[100005];

int main() {
    LL n, m, v, p;
    cin >> n >> m >> v >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, [](LL x, LL y) { return x > y; });
    // for (int i = 0; i < n; i++) {
    //     printf("%lld ", a[i]);
    // }
    // puts("");
    LL ans;
    LL agg = 0;
    for (ans = p; ans < n; ans++) {
        // 前後都還夠塞
        LL les = n - ans;
        LL re = v - (p - 1) - les;
        agg += a[ans - 1];
        if (re <= 0) {
            if (a[p - 1] <= a[ans] + m) {
                continue;
            } else {
                break;
            }
        } else {
            // 要開始塞中間了
            LL space = (ans - p + 1) * (a[ans] + m) - agg;
            LL vote = re * m;
            // printf("ans = %lld, re = %lld, space = %lld, vote = %lld\n", ans, re, space, vote);
            if (a[p - 1] <= a[ans] + m && space >= vote) {
                continue;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
}

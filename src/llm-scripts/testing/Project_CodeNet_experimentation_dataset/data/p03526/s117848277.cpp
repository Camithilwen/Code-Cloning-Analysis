#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fr first
#define sc second
#define ii pair < ll, ll >

const int N = (int)5e3 + 7;
const ll inf = (ll)1e18 + 7;

ii p[N];
ll dp[N];

bool comp (const ii &a, const ii &b) {
    return a.fr + a.sc < b.fr + b.sc;
}

main() {
    int n; scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%lld %lld", &p[i].fr, &p[i].sc);
    }
    sort(p, p + n, comp);
    for (int i = 0; i <= n; i++) {
        dp[i] = inf;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (p[i].fr >= dp[j]) {
                dp[j + 1] = min(dp[j + 1], dp[j] + p[i].sc);
            }
        }
    }
    int m = n;
    while (dp[m] == inf) m--;
    printf ("%d", m);
}

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

const int N = 1e5+34;

int a[N];

void solve() {
    int n; scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        sum += abs(a[i]-a[i-1]);
    }
    sum += abs(a[n]);
    debug(sum);
    for (int i = 1; i <= n; ++i) {
        int cur = sum-abs(a[i]-a[i-1]);
        if (i == n) {
            cur -= abs(a[i]);
            cur += abs(a[i-1]);
        } else {
            cur -= abs(a[i+1]-a[i]);
            cur += abs(a[i+1]-a[i-1]);
        }
        printf("%d\n", cur);
    }
}

int main() {
    init();
    int t = 1; //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
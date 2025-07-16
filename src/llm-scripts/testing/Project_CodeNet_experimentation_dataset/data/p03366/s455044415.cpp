#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;

typedef long long ll;
#define pb push_back

int n, s;
int x[N + 5], p[N + 5];

int main() {
#ifdef Wearry 
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", x + i, p + i);
    }

    vector<int> res;
    int l = 1, r = n;
    ll tl = 0, tr = 0;

    while(l <= n && x[l] < s && r >= 1 && x[r] > s) {
        if(tl + p[l] >= tr + p[r]) {
            tl += tr + p[r];
            tr = 0;
            res.pb(r --);
        } else {
            tr += tl + p[l];
            tl = 0;
            res.pb(l ++);
        }
    }

    while(l <= n && x[l] < s) res.pb(l ++);
    while(r >= 1 && x[r] > s) res.pb(r --);

    ll ans = 0;
    for(int i = (int) res.size() - 1; i >= 0; --i) {
        ans += abs(s - x[res[i]]);
        s = x[res[i]];
    }
    printf("%lld\n", ans);

    return 0;
}

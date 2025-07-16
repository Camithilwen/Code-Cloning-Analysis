#include<bits/stdc++.h>

using namespace std;


int main(void) {
    constexpr long MOD = 1e9 + 7;

    long n, m;
    cin >> n >> m;
    vector<long> a(n), b(m);
    for(auto &e: a) cin >> e;
    for(auto &e: b) cin >> e;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long x = 0, y = 0;

    auto aidx = [&](long x) {
        auto i = lower_bound(a.begin(), a.end(), x) - a.begin();
        return a[i] == x ? i : -1;
    };
    auto bidx = [&](long x) {
        auto i = lower_bound(b.begin(), b.end(), x) - b.begin();
        return b[i] == x ? i : -1;
    };

    long r = 1;
    for(int i=m*n; i>=1; i--) {
        long ai = aidx(i), bi = bidx(i);

        if(ai>=0 && bi>=0) {
            x++, y++;
            continue;
        }

        if(ai>=0) {
            x++;
            r *= y, r %= MOD;
            continue;
        }

        if(bi>=0) {
            y++;
            r *= x, r %= MOD;
            continue;
        }

        r *= x*y - (m*n - i), r %= MOD;
    }

    cout << r << endl;
}

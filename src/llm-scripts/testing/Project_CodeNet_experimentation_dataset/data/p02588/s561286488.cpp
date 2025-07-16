#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> cnt;
    for (int i = 1; i <= n; ++i) {
        long double ai;
        cin >> ai;
        ll val = (ll) (ai * 1000000000.0 + 0.5);
        ll cnt2 = 0;
        ll cnt5 = 0;
        while (val % 2 == 0) {
            cnt2++;
            val /= 2;
        }
        while (val % 5 == 0) {
            cnt5++;
            val /= 5;
        }
        cnt[make_pair(cnt2, cnt5)]++;
    }

    ll ans = 0;
    for (const auto &pi: cnt) {
        for (const auto &pj: cnt) {
            if (pi.first.first + pj.first.first >= 18 &&
                pi.first.second + pj.first.second >= 18) {
                if (pi == pj) {
                    ans += pi.second * (pi.second - 1ll);
                } else {
                    ans += pi.second * 1ll * pj.second;
                }
            }
        }
    }
    cout << ans / 2 << endl;
}
int main(){
	solve();
}


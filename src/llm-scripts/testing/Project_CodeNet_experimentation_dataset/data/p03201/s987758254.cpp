#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    map<ll, int> mp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll A;
        cin >> A;
        mp[A]++;
    }
    int ans = 0;
    for (auto ite = mp.rbegin(); ite != mp.rend(); ++ite) {
        if (ite->second == 0) continue;

        ll x = pow(2, floor(log2(ite->first)) + 1);
        auto ite1 = mp.lower_bound(x - ite->first);

        if (ite1->first + ite->first == x) {
            if (ite1->first == ite->first) {
                int c = ite->second / 2;
                ite->second -= c;
                ite1->second -= c;
                ans += c;
            } else {
                int c = min(ite->second, ite1->second);
                ite->second -= c;
                ite1->second -= c;
                ans += c;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
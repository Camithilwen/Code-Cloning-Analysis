#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i,N) cin >> a.at(i);
    ll ans = 0;
    rep(i,N) {
        if (i == 0) continue;
        if(a.at(i) + a.at(i-1) > x) {
            ll diff = a.at(i) + a.at(i-1) - x;
            ans += diff;
            if (diff <= a.at(i)) a.at(i) -= diff;
            else a.at(i) = 0;
        }
    }
    cout << ans << endl;
}


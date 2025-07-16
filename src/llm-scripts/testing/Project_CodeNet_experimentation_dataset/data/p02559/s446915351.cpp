#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, Q, t, a;
    cin >> N >> Q;
    atcoder::fenwick_tree<ll> ft(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        ft.add(i, a);
    }
    vector<ll> ans;
    for ( int q = 0; q < Q; q++ ) {
        cin >> t;
        if ( t == 0 ) {
            ll p, x;
            cin >> p >> x;
            ft.add(p,x);
        } else {
            ll l, r;
            cin >> l >> r;
            ans.push_back(ft.sum(l,r));
        }
    }
    for ( auto a : ans ) {
        cout << a << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}
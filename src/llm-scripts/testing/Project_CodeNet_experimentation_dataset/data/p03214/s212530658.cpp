#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll s = 0;
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
        s += A[i];
    }
    ll m = 1000000, ix = 0;
    for ( int i = 0; i < N; i++ ) {
        ll x = abs(A[i]*N-s);
        if ( m > x ) {
            m = x;
            ix = i;
        }
    }
    return ix;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}
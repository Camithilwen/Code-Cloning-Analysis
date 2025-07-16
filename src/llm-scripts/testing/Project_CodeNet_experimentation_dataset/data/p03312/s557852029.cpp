#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(vector<ll>& A) {
    int n = A.size();
    vector<ll> C(n+1);
    for ( int i = 0; i < n; i++ ) {
        C[i+1] = C[i] + A[i];
    }

    auto diff = [](ll m1, ll m2) {
        return max(m1,m2) - min(m1,m2);
    };

    int i1,i2,i3;
    ll ans = 1LL<<60;
    for ( i2 = 2; i2 <= n-2 ; i2++ ) {
        i1 = lower_bound(C.begin(), C.end(), (C[i2]+1)/2) - C.begin();
        if ( i1 >= 2 ) {
            if ( diff(C[i2]-C[i1-1],C[i1-1]-C[0]) < diff(C[i2]-C[i1],C[i1]-C[0]) ) i1--;
        }
        if ( i1 <= 0 ) i1 = 1;
        if ( i1 >= i2 ) i1 = i2-1;

        i3 = lower_bound(C.begin(), C.end(), C[i2] + ((C[n]-C[i2])+1)/2 ) - C.begin();
        if ( i3 > n ) i3 = n;
        if ( i3 >= i2+2 ) {
            if ( diff(C[n]-C[i3-1],C[i3-1]-C[i2]) < diff(C[n]-C[i3],C[i3]-C[i2]) ) i3--;
        }
        if ( i3 <= i2 ) i3 = i2+1;
        if ( i3 >= n ) i3 = n-1;

        ll x = max({C[i1],C[i2]-C[i1],C[i3]-C[i2],C[n]-C[i3]}) - min({C[i1],C[i2]-C[i1],C[i3]-C[i2],C[n]-C[i3]});
        if ( ans > x ) ans = x;
    }

    return ans;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }    
    auto ans = solve(A);
    cout << ans << "\n";
    return 0;
}
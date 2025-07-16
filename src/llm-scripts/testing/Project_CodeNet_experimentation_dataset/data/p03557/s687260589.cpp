#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
    int n;
    cin >> n;

    vi A(n), B(n), C(n);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    rep(i,n) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    rep(i,n){
        ll x = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll y = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += x * y;
        //cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}

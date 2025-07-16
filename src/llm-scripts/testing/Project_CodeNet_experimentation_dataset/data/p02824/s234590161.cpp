#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

// 二分探索
// 求める点以上の場合にtrueを返すよう実装する。
template <class V>
V binary_search(V _l, V _r, function<bool(V)> f) {
    V l = _l, r = _r;
    while(r>l) {
        ll mid = (l+r)/2;
        if (f(mid)) {
            r = mid;
        } else {
            l = mid;
        }
        if (l+1==r) {
            if (f(l)) {
                r = l;
            } else {
                l = r;
            }
        }
    }
    return l;
}

/* verified by atcoder agc 041 b
   https://atcoder.jp/contests/agc041/tasks/agc041_b */
vector<ll> a;
ll n,m,v,p;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>v>>p;
    a.assign(n,0);
    rep(i,n) cin>>a[i];
    sort(begin(a), end(a));
    function<bool(ll)> chk = [&](ll idx) {
        if (a[idx]+m<a[n-p]) {
            return false;
        }
        ll cnt = 0;
        rep(i,n) {
            if (i>n-p||i<=idx) {
                cnt += m;
            }
            else {
                cnt += max(0LL, a[idx]+m-a[i]);
            }
        }
        return cnt >= m*v;
    };
    ll l = binary_search(0LL, n-1, chk);
    cout << n-l << endl;
    return 0;
}

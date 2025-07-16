#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
#define all(x) begin((x)), end((x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}

vector<ll> a;
ll n,m,v,p;
bool chk(int idx) {
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
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>v>>p;
    a.assign(n,0);
    rep(i,n) cin>>a[i];
    sort(all(a));
    ll l=0,r=n-1;
    while(r>l) {
        ll mid = (l+r)/2;
        if (chk(mid)) {
            r = mid;
        } else {
            l = mid;
        }
        if (l+1==r) {
            if (chk(l)) {
                r = l;
            } else {
                l = r;
            }
        }
    }
    cout << n-l << endl;
    return 0;
}

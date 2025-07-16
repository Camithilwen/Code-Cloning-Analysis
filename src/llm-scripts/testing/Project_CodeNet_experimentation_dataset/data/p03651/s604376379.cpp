#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
int main() {
    int n;
    ll k, p;
    cin >> n >> k >> p;
    ll m = p;
    rep(i, 1, n){
        ll q;
        cin >> q;
        p = gcd(p, q);
        m = max(m, q);
    }
    if(k%p == 0 && k <=m) cout << "POSSIBLE" << endl; 
    else cout << "IMPOSSIBLE" << endl;
}
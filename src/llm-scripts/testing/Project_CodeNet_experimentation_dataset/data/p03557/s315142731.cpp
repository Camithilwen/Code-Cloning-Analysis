#include <bits/stdc++.h>
#include<math.h>
#include<algorithm>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using vi = vector<int> ;
using vvi = vector<vector<int>> ;
using vl = vector<ll> ;
using vvl = vector<vector<ll>> ; 
using vs = vector<string> ; 
using vvs = vector<vector<string>> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    ll n ;
    cin >> n ;
    vl a(n), b(n), c(n) ;
    rep(i, n) cin >> a[i] ;
    rep(i, n) cin >> b[i] ;
    rep(i, n) cin >> c[i] ;
    sort(a.begin(), a.end()) ;
    sort(b.begin(), b.end()) ;
    sort(c.begin(), c.end()) ;
    ll ans = 0 ;
    rep(i, n){
        ll u = (lower_bound(a.begin(), a.end(), b[i]) - a.begin()) ;
        ll v = n - (upper_bound(c.begin(), c.end(), b[i]) - c.begin()) ;
        ans += u * v ;
    }
    cout << ans << endl ;
} 
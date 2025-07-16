#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll, ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int modpow(ll a, ll n){
    if(n == 0) return 1 ;
    if(n == 1) return a % mod ;
    if(n % 2) return (a * modpow(a, n-1))%mod ;
    ll t = modpow(a, n/2) ;
    return (t*t) % mod ;
}

int main() {
    ll n ;
    cin >> n ;
    vector<ll> a (n) ;
    vector<ll> c (60) ;
    rep(i, n) {
        cin >> a[i] ;
        rep(j, 60){
            if(a[i] >> j & 1){
                c[j]++ ;
            }
        }
    }
    ll ans = 0 ;
    ll k =  n;
    rep(i, n){
        rep(j, 60){
            if(a[i] >> j & 1){
                ans += modpow(2,j)*(k - c[j]) ;
                ans %= mod ;
                c[j]-- ;
            }
            else {
                ans += modpow(2,j)*c[j] ;
            }
        }
        k-- ;
    }
    cout << ans << endl ;
} 
#include<bits/stdc++.h>
using namespace std;    
#define ll long long

class Combination {
    /*
        :)
    */
   public :

    const int mod = 1e9 + 7;

    ll add(ll x, ll y) {
        x += y;
        if (x >= mod) return x - mod;
        return x;
    }
    ll sub(ll x, ll y) {
        x -= y;
        if (x < 0) return x + mod;
        return x;
    }
    ll mult(ll x, ll y) {
        return (x * y) % mod;
    }
    ll bin_pow(ll x, ll p) {
        if (p == 0) return 1;
        if (p & 1) return mult(x, bin_pow(x, p - 1));
        return bin_pow(mult(x, x), p / 2);
    }
    ll rev(ll x) {
        return bin_pow(x, mod - 2);
    }
    ll fact(ll a) {
        ll S = 1;
        for (ll I = 1 ; I <= a; I++)S = S *  I % mod;
        return S;
    }
    ll Combin(ll x, ll y) {
        return mult(fact(x), rev(mult(fact(sub(x, y)), fact(y))));
    } 
};
int main () {
    ios_base::sync_with_stdio(false), cin.tie(0);
    Combination cm;
    ll ans = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    ll araysum = 0;
    for (int i = 0 ; i < n; i++) araysum = cm.add(araysum, a[i]);
    ll S = cm.mult(araysum, araysum);
    ll Si = 0;
    for (int i = 0 ; i < n; i++) {
      Si = cm.add(Si, cm.mult(a[i], a[i])); 
    }
    ans = cm.mult(cm.sub(S, Si), cm.rev(2));
    cout << ans ;
}
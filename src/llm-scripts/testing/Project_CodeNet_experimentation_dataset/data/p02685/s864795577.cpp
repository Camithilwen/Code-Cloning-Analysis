#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
vector<ll> fac(200005);
vector<ll> ifac(200005);
ll modpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        n = n >> 1;
    }
    return ans;
}
ll comb(ll a, ll b){
    if(a == 0 && b == 0)
        return 1;
    if(a < b || a < 0)
        return 0;
    ll tmp = ifac[a - b] * ifac[b] % mod;
    return tmp * fac[a] % mod;
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    fac[0] = 1;
    ifac[0] = 1;
    for(ll i = 0; i < n; i++){
        fac[i + 1] = fac[i] * (i + 1) % mod;
        ifac[i + 1] = ifac[i] * modpow(i + 1, mod - 2) % mod;
    }
    ll ans = 0;
    n--;
    for(int i = 0; i <= k; i++){
        ll p = modpow(m - 1, n - i) * comb(n, i) % mod;
        ans = (ans + p) % mod;
    }
    ans = ans * m % mod;
    cout << ans << endl;
    return 0;
}
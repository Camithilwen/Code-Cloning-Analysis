#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod_pow(int n, int e, int mod){
    int ans = 1;
    n = n % mod;
    while(e != 0){
        if(e % 2 == 1){
            ans = (ans * n) % mod;
        }
        e /= 2;
        n = (n * n) % mod;
    }
    return ans;
}

int mod_inv(int n, int mod){
    return mod_pow(n, mod-2, mod);
}

int mod_combination(int n, int k, int mod){
    if(n < k || k < 0) return 0;
    if(n-k < k) k = n-k;
    int ans = 1;
    for(int i=1; i<=k; i++){
        ans = (((ans * (n+1-i)) % mod) * mod_inv(i, mod)) % mod;
    }
    return ans;
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int mod = 998244353;
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;
    int combi = 1;
    if(m == 1){
        if(k == n-1){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        return 0;
    }
    int m_1_pow = mod_pow(m-1, n-1, mod);
    int m_1_inv = mod_inv(m-1, mod);
    for(int l=0; l<=k; l++){
        ans = (ans + (((combi * m_1_pow) % mod) * m) % mod) % mod;
        m_1_pow = (m_1_pow * m_1_inv) % mod;
        combi = (((combi * (n-1-l)) % mod) * mod_inv(l+1, mod)) % mod;
    }
    cout << ans << endl;

    return 0;
}
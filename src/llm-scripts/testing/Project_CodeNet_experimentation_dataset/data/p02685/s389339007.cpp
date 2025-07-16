#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0;i<(n);i++)
typedef long long ll;


ll modpow(ll a, ll n, ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res = res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

ll modinv(ll a, ll mod){
    return modpow(a, mod-2, mod);
}


int main() {
    ll N,M,K,ans;
    cin>>N>>M>>K;
    ll mod = 998244353;
    ll kakuk = M*modpow(M-1,N-1,mod)%mod;
    ans = kakuk;
    ll gyakuM = modinv(M-1,mod);
    rep(i,K){
        kakuk = (kakuk * (N-i-1))%mod;
        kakuk = (kakuk * modinv(i+1,mod))%mod;
        kakuk = (kakuk * gyakuM)%mod; 
        ans += kakuk;
        ans = ans%mod;
    }
    if(M==1&&N-1==K) cout << 1 << endl;
    else cout << ans << endl;
}
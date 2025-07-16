#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=1000000007;

ll fac[200007],finv[200007],inv[200007];
void cominit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<200007;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll com(ll n,ll k){
    if(n<k)return 0;
    if(n<0 || k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,a,b;
    cin>>h>>w>>a>>b;
    h--;w--;
    cominit();
    ll ans=com(h+w,w);
    for(ll i=0LL;i<a;i++){
        ans-=((com(b-1+h-i,b-1))*(com(w-b+i,i)))%mod;
        ans%=mod;
    }
    cout <<(ans+mod)%mod<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 998244353
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59


vector<ll> bi(5010101);


ll modinv(ll a) {
    ll m=Mod;
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll comb(ll s,ll t){
    ll q=bi[s]*modinv(bi[t]);
    q%=Mod;
    q*=modinv(bi[s-t]);
    q%=Mod;
    return q;
}

int main(){
    ll i,j;
    ll n,m;
    cin>>n>>m;

    bi[0]=1;

    for(i=1;i<5010101;i++){
        bi[i]=bi[i-1]*i;
        bi[i]%=Mod;
    }

    ll ans1=comb(3*m+n-1,n-1);
    ll ans2=n*comb(m+n-2,n-1);

    ans2%=Mod;
    
    ll hoge=(ans1-ans2+Mod)%Mod;

    if(n<=m) cout<<hoge<<endl;
    else{
        ll l;
        ll ans3=0;
        for(l=m+1;l<=min(3*m,n);l++){
            if((3*m-l)%2==0) {
                ans3+=comb(n,l)*comb((3*m-l)/2+n-1,n-1);
                ans3%=Mod;
            }
        }

         cout<<(hoge+Mod-ans3)%Mod<<endl;
    }







    return 0;
}
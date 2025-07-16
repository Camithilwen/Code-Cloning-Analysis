#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e6+100,mod=998244353;
ll power(ll n,ll k){
    if (k==0) return 1;
    if (k%2==1){
        ll x=power(n,k/2);
        return x*x%mod*n%mod;
    }
    ll x=power(n,k/2);
    return x*x%mod;
}
ll fac[N],fm[N];
ll ent(ll k,ll n){
    if (k<0 || k>n) return 0;
    if (k==0 || k==n) return 1;
    return fac[n]*fm[k]%mod*fm[n-k]%mod;
}
int32_t main(){
    fac[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        fm[i]=power(fac[i],mod-2);
    }
 //   cout << ent(3,5) << endl;
    ll ans=0;
    ll n,m;
    cin >> n >> m;
    ll z=3*m;
    for (int i=0;i<=min(n,m);i++){
        ll t=z-i;
        if (t%2==1) continue;
        ans+=ent(i,n)*ent(n-1,n-1+t/2)%mod;
    }
    for (int i=2*m+1;i<=3*m;i++){
        ll t=z-i;
        ans-=n*ent(n-2,n-2+t)%mod;
        ans+=mod;
        ans%=mod;
    }
    cout << ans << endl;
}

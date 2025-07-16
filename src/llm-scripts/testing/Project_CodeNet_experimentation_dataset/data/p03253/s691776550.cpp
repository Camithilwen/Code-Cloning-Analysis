#include<bits/stdc++.h>
#include <algorithm>
#include <complex>

using namespace std;
typedef long long ll;
typedef complex<long double> point;
const ll N = 2e5+5,mod=1e9+7,inf=1e9+5;
long double pi=3.14159265359;
ll a[N],b[N],inv[N],fact[N];
int n,c;
ll fp(int base,int exp){
    if(exp==0)return 1;
    ll ans=fp(base,exp/2);
    ans=(ans*ans)%mod;
    if(exp%2)
        ans=(ans*base)%mod;
    return ans;
}
ll ncr(int n,int r){
return ((fact[n]*inv[n-r])%mod*inv[r])%mod;
}
int main()
{
    iostream::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int n,m,mm;
     inv[0]=fact[0]=1;
     for(int i=1;i<2e5;i++){
        fact[i]=(i*fact[i-1])%mod;
        inv[i]=fp(fact[i],mod-2);
     }

     cin>>n>>m;
     mm=m;
     ll ans=1;
     for(int i=2;i*i<=m;i++){
            int c=0;
        while(m%i==0){
            m/=i;
     c++;
        }

        ans*=ncr(n+c-1,c);
        ans%=mod;
     }
     if(m>1){
        ans*=n;

        ans%=mod;
     }
     cout<<ans;

    return 0;
}

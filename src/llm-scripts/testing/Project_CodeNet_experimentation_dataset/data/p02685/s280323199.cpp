#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,k,ans=0,tmp=1;
ll power(ll a,ll b) {return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
int main()
{
    cin>>n>>m>>k;
    for(ll i=0;i<=k;i++){
        ans=(ans+(tmp*m%mod)*power(m-1,n-i-1))%mod;
        tmp=tmp*(n-i-1)%mod*power(i+1,mod-2)%mod;
    }
    cout<<ans;
    return 0;
}
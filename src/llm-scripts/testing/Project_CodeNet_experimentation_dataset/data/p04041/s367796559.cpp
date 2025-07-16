#include<bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
ll d[45][1<<17];
ll n,x,y,z;
int main()
{
    scanf("%lld%lld%lld%lld",&n,&x,&y,&z);
    ll ans=1;
    for(ll i=1;i<=n;i++)
    {
        ans=1ll*ans*10;
        ans%=mod;
    }
    ll s=(1<<x+y+z)-1;
    ll u=(1<<x-1)|(1<<x+y-1)|(1<<x+y+z-1);
    d[0][0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=s;j++)
        {
            for(ll k=1;k<=10;k++)
            {
                ll t=(j<<k)|(1<<k-1);
                t&=s;
                if((t&u)!=u)
                {
                    d[i][t]=(d[i][t]+d[i-1][j])%mod;
                }
            }
        }
    }
    for(ll i=0;i<=s;i++)
    {
        ans=(ans-d[n][i]+mod)%mod;
    }
    cout<<ans%mod<<endl;
}

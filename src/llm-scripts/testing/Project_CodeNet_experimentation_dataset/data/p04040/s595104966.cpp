#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
ll modInv(ll a)
{
    ll res=1;
    ll b=mod-2;
    while(b)
    {
        if(b&1)
        res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    vector<ll> fac(200020,1),facInv(200020,1);
    for(int i=2;i<=200010;i++)
    {
        fac[i]=(i*fac[i-1])%mod;
        facInv[i]=modInv(fac[i]);
    }
    // cin>>t;
    while(t--)
    {
        ll h,w,a,b;
        cin>>h>>w>>a>>b;
        ll ans=0,ans2=0;
        ans2=fac[h+w-2];
        ans2=(ans2*facInv[h-1])%mod;
        ans2=(ans2*facInv[w-1])%mod;
        for(int i=1;i<=a;i++)
        {
            ll res=1,res2=1;
            res2=fac[a-i+w-b-1];
            res2=(res2*facInv[a-i])%mod;
            res2=(res2*facInv[w-b-1])%mod;
            res=fac[h-a+i+b-2];
            res=(res*facInv[h-a+i-1])%mod;
            res=(res*facInv[b-1])%mod;
            res=(res*res2)%mod;
            // cout<<res<<" ";
            ans=(ans+res)%mod;
        }
        ans=((ans2-ans)%mod+mod)%mod;
        cout<<ans<<"\n";
    }
    return 0;
}
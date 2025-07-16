#include<bits/stdc++.h>
using namespace std;
#define M ((ll)(1e9)+7)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
typedef long long ll;
ll power(ll x,ll y)
{
    if(y==0)
    return 1;
    ll res=power(x,y/2);
    res=(res*res)%M;
    if(y&1)
    res=(res*x)%M;
    return res;
}
void solve()
{
    ll h,w,a,b,va;
    cin>>h>>w>>a>>b;
    a=h-a+1;
    ll ta=a-1,tb=b+1;
    ll fact[200001];fact[0]=1;
    for(ll i=1;i<200001;i++)
    fact[i]=(fact[i-1]*i)%M;
    vector<ll> v,v1;
    for(ll i=tb;i<=w;i++)
    {
        va=fact[i+ta-2];
        va=(va*power(fact[i-1],M-2))%M;
        va=(va*power(fact[ta-1],M-2))%M;
        v.pb(va);
    }
    for(ll i=tb;i<=w;i++)
    {
        va=fact[h+w-a-i];
        va=(va*power(fact[h-a],M-2))%M;
        va=(va*power(fact[w-i],M-2))%M;
        v1.pb(va);
    }
    //cout<<v[0]<<" "<<v[1]<<" "<<v1[0]<<" "<<v1[1]<<endl;
    ll ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans=(ans+(v[i]*v1[i])%M)%M;
    }
    cout<<ans<<endl;
}
int main()
{
    solve();
}

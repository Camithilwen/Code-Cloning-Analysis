#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int
#define mod 998244353
using namespace std;
int fact[200005];
int power(int a, int b)
{
    if(b==0)
        return 1;
    int t = power(a,b/2);
    t*=t;
    t%=mod;
    if(b&1)
        t*=a;
    return t%mod;
}

int ncr(int n, int r)
{
    if(r==0)
        return 1;
    int ans=1;
    ans*=fact[n];
    ans%=mod;
    ans*=power(fact[r],mod-2);
    ans%=mod;
     ans*=power(fact[n-r],mod-2);
    ans%=mod;

    return ans;
}

void solve()
{
    fact[1]=1;
    fact[0]=1;
    for(int i=2;i<200005;i++)
        fact[i]=fact[i-1]*i%mod;
    int n,m,k;
    cin>>n>>m>>k;
    if(m==1)
    {
        if(k==n-1)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        return;
    }
    int ans=0;
    for(int i=0;i<=k;i++)
    {
        int g = ncr(n-1,i);
        // cout<<g<<endl;
        int t = (g*m%mod)*power(m-1,n-1-i)%mod;
        ans+=t;
        ans%=mod;

    }
    
    cout<<ans<<endl;



}
signed main()

{
    FAST_IO;
    int t = 1;

    // cin>>t;

    while(t--)
    {
        solve();
    }
    
    return 0;
}
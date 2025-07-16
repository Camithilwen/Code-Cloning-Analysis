#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55,mod=1e9+7,inf=2000000000;
int n,a[N];
char s[N];
unordered_map<ll,int>vis[20][20];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    int up=1<<n;
    for(int i=0;i<up;i++)
    {
        ll sum1=0,sum2=0,a=__builtin_popcount(i),b=n-a;
        for(int j=1;j<=n;j++)
            if(i>>j-1&1)
            sum1=(sum1*2333%mod+s[j]-'a')%mod;
            else sum2=(sum2*2333%mod+s[j]-'a')%mod;
        //cout<<a<<' '<<b<<' '<<sum1*inf+sum2<<endl;
        vis[a][b][sum1*inf+sum2]++;
    }
    reverse(s+1,s+1+n+n);
    ll ans=0;
    for(int i=0;i<up;i++)
    {
        ll sum1=0,sum2=0,a=__builtin_popcount(i),b=n-a;
        for(int j=1;j<=n;j++)
            if(i>>j-1&1)
            sum1=(sum1*2333%mod+s[j]-'a')%mod;
            else sum2=(sum2*2333%mod+s[j]-'a')%mod;
        //cout<<a<<' '<<b<<' '<<sum1*inf+sum2<<endl;
        ans+=vis[b][a][sum2*inf+sum1];
    }
    printf("%lld\n",ans);
}

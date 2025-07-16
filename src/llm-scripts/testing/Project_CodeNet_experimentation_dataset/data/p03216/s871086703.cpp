#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,q;
char s[N];
ll dp[N],f[N],sumd[N],summ[N];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
    {
        sumd[i]=sumd[i-1]+(s[i]=='D');
        summ[i]=summ[i-1]+(s[i]=='M');
        dp[i]=dp[i-1];
        f[i]=f[i-1];
        if(s[i]=='M') dp[i]+=sumd[i];
        if(s[i]=='C') f[i]+=dp[i];
    }
    while(q--)
    {
        ll ans=f[n];
        int k;scanf("%d",&k);
        for(int i=k;i<=n;i++)
            if(s[i]=='C')
            ans-=dp[i-k]+(summ[i]-summ[i-k])*sumd[i-k];
        printf("%lld\n",ans);
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4005,mod=998244353;
int k,n,c[N][N];
ll C(int n,int m)
{
    if(m==0||n==m) return 1;
    if(m==1) return n;
    if(c[n][m]) return c[n][m];
    return c[n][m]=(C(n-1,m-1)+C(n-1,m))%mod;
}
ll solve(int x)
{
    ll ans=0;
    int up=0;
    for(int i=1;i<=x/2;i++)
        if(i<=k&&x-i<=k)
        up++;
    for(int j=0,f=1;j<=up&&n-2*j>=0;j++,f*=-1)
        ans=(ans+f*C(up,j)%mod*C(n-2*j+k-1,k-1))%mod;
    return (ans+mod)%mod;
}
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=2;i<=2*k;i++)
        printf("%lld\n",solve(i));
}

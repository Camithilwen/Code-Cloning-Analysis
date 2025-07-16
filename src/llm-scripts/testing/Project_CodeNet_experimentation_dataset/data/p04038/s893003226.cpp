#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
void read(T &x)
{
    x=0;char c=getchar();bool p=0;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')p=1;
    for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+(c^48);
    if(p)x=-x;
}
const ll MOD=1000000000+7;
ll f[2005][2005];
ll fac[4000005],inv[4000005];
int n,k;
ll ksm(ll basic,ll mi)
{
    ll tmp=1;
    while(mi)
    {
        if(mi&1)tmp=tmp*basic%MOD;
        mi>>=1;
        basic=basic*basic%MOD;
    }
    return tmp;
}
ll C(ll x,ll y)
{
    return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}
int main()
{
    read(n),read(k);
    fac[0]=inv[0]=1;
    for(ll i=1;i<=n*k;++i)fac[i]=fac[i-1]*i%MOD;
    inv[n*k]=ksm(fac[n*k],MOD-2);
    for(ll i=n*k-1;i;--i)inv[i]=inv[i+1]*(i+1)%MOD;
    if(k==1)
    {
        printf("1\n");
        return 0;
    }
    f[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        f[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            f[i][j]=(f[i][j]+f[i-1][j]+1ll*f[i][j-1]*(n-j+1)%MOD*C(n*k-i-(j-1)*(k-1)-1,k-2)%MOD)%MOD;
        }
    }
    printf("%lld\n",f[n][n]);
    return 0;
}
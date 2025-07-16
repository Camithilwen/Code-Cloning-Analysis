#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
#define MOD 998244353
#define LL long long int
LL ans,res,C[MAXN],fac[MAXN],revfac[MAXN];
int n,m,k;
LL qpow(LL a,int b)
{
    LL tmp=1;
    while(b)
    {
        if(b&1)
        tmp=tmp*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return tmp%MOD;
}
void facrev()
{
    C[0]=1;
    C[1]=(n-1);
    fac[1]=1;
    fac[0]=1;
    revfac[0]=1;
    revfac[1]=1;
    for(int i=2;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%MOD;
        C[i]=C[i-1]*(n-i)%MOD;
    }
    revfac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=1;i--)
    {
        revfac[i]=revfac[i+1]*(i+1)%MOD;
        C[i]=C[i]*revfac[i]%MOD;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    facrev();
    int p=n-k;
    res=m;
    for(int i=1;i<=p-1;i++)
    {
        res=res*(m-1)%MOD;
    }
    ans=res*C[p-1]%MOD;
    for(int j=p+1;j<=n;j++)
    {
        res=res*(m-1)%MOD;
        ans=(ans+res*C[j-1]%MOD)%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
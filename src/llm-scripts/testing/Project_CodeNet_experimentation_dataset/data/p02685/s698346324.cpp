#include<iostream>
using namespace std;
long long p=998244353,jc[200010],n,m,k,f[200010],ans;
long long ksm(long long a,long long b)
{
     long long x=1;
     for(;b;a=(a*a)%p,b/=2) if(b%2==1) x=(x*a)%p;
     return x;
}
long long c(long long x,long long y)
{
     long long z=jc[x];
     if(y<=0) return 1;
     z=(z*ksm(jc[y],p-2))%p;
     z=(z*ksm(jc[x-y],p-2))%p;
     return z;
}
int main()
{
    int i;
    cin>>n>>m>>k;
    jc[0]=1;
    for(i=1;i<=n;i++) jc[i]=(jc[i-1]*i)%p;
    f[1]=m;
    for(i=2;i<=n;i++) f[i]=(f[i-1]*(m-1))%p;
    for(i=0;i<=k;i++) ans=(ans+c(n-1,n-i-1)*f[n-i])%p;
    cout<<ans;
    cin>>i;
}
    

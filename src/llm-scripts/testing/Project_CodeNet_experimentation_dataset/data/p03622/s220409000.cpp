#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define maxn 1000005
#define mod 998244353
using namespace std;
int n,m,fac[maxn],inv[maxn],ans;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int mul(int a,int b){return 1ll*a*b%mod;}
int ksm(int a,int b)
{
    int s=1;
    for(;b;b>>=1,a=mul(a,a))
        if(b&1) s=mul(s,a);
    return s;
}
int C(int a,int b) {return mul(fac[a],mul(inv[b],inv[a-b]));}
int main()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=mul(fac[i-1],i),inv[i]=ksm(fac[i],mod-2);
    scanf("%d%d",&n,&m);
    if(n<m) swap(n,m);
    for(int i=1;i<=m;i++)
        ans=add(ans,mul(C(i+i,i),C(n+m-2*i,n-i)));
    ans=mul(ans,mul((mod+1)/2,ksm(C(n+m,n),mod-2))),printf("%d\n",add(ans,n));
    return 0;
}
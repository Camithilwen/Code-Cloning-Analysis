#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const long long mod=1000000007;
const int maxn=200005;
ll inv[maxn],s[maxn];
int N,n,m,x,y;
ll Pow(ll a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll C(int a,int b)
{
	if(a<0||b<0)
		return 1;
	return s[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
    scanf("%d%d",&x,&y);
    N=n+m-2;
    s[0]=1;
    for(int i=1;i<=N;i++)
    	s[i]=s[i-1]*i%mod;
    inv[0]=1;
    inv[N]=Pow(s[N],mod-2);
    for(int i=N-1;i>0;i--)
    	inv[i]=inv[i+1]*(i+1)%mod;
    ll ans=0;
    for(int i=y+1;i<=m;i++)
    {
    	ans+=C(n-x+i-2,i-1)*C(x+m-i-1,x-1)%mod;
    	ans%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200005,K=998244353;
int n,m,p,ans,fac[maxn],inv[maxn];
int C(int A,int B) { return (LL)fac[A]*inv[B]%K*inv[A-B]%K; }
int Pow(int A,int B)
{
	int res=1;
	while (B)
	{
		if (B&1) res=(LL)res*A%K;
		A=(LL)A*A%K;
		B>>=1;
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&p,&m);
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(LL)fac[i-1]*i%K;
	inv[n]=Pow(fac[n],K-2);
	for (int i=n-1;i>=0;i--) inv[i]=(LL)inv[i+1]*(i+1)%K;
	for (int i=m,now=(LL)p*Pow(p-1,n-m-1)%K;i>=0;i--)
	{
		//cerr<<">>>>>>"<<now<<endl;
		ans=(ans+(LL)now*C(n-1,i))%K;
		now=(LL)now*(p-1)%K;
	}
	printf("%d\n",ans);
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=6100;
int n,mod,fac[N],inv[N],tot[4][N],invtot[4][N];
int p[N];
inline void add(int &a,int b){a=(a+b)%mod;}
inline void del(int &a,int b){a=(a-b+mod)%mod;}
inline void mul(int &a,int b){a=(a*b)%mod;}
inline int C(int n,int m){return fac[n]*inv[n-m]%mod*inv[m]%mod;}
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a);
		b>>=1;
		mul(a,a);
	}
	return ans;
}
signed main()
{
	scanf("%lld%lld",&n,&mod);n*=3;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%mod;
	p[0]=1;
	for (int i=1;i<=n;i++) p[i]=(p[i-1]*2)%mod;
	for (int i=1;i<=3;i++)
	{
		for (int j=0;j<i;j++) tot[i][j]=1;
		for (int j=i;j<=n;j++) tot[i][j]=(tot[i][j-i]*C(j,i))%mod;
		for (int j=0;j<=n;j++) invtot[i][j]=m_pow(tot[i][j],mod-2);
	}
	int ans=0;
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			int k=n-i-2*j,num=1,tmp=n;
			if (k<0) break;
			if (k%3!=0) continue;
			k/=3;
			mul(num,tot[1][tmp]*invtot[1][tmp-i]%mod);tmp-=i;
			mul(num,tot[2][tmp]*invtot[2][tmp-2*j]%mod);tmp-=2*j;
			mul(num,tot[3][tmp]);
			mul(num,inv[i]);mul(num,inv[j]);mul(num,inv[k]);
			mul(num,p[k]);
//			printf("1:%d 2:%d: %d\n",i,j,num);
			add(ans,num);
		}
	}
	printf("%lld\n",ans);
}
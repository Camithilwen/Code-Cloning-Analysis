#include<bits/stdc++.h>
using namespace std;
int n,mod,jc[11111],injc[11111],ans,ipw1[11111],ipw2[11111],ipw3[11111],i2,i3,ct,pw[11111];
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&mod);
	jc[0]=1;
	for (int i=1;i<=3*n;i++)
	{
		jc[i]=1ll*jc[i-1]*i%mod;
	}
	injc[3*n]=binpow(jc[3*n],mod-2);
	for (int i=3*n-1;i>=0;i--)
	{
		injc[i]=1ll*injc[i+1]*(i+1)%mod;
	}
	ipw1[0]=ipw2[0]=ipw3[0]=1;i2=binpow(2,mod-2);i3=binpow(6,mod-2);
	for (int i=1;i<=3*n;i++)
	{
		ipw1[i]=1;ipw2[i]=1ll*ipw2[i-1]*i2%mod;
		ipw3[i]=1ll*ipw3[i-1]*i3%mod;
	}
	pw[0]=1;
	for (int i=1;i<=3*n;i++) pw[i]=2ll*pw[i-1]%mod;
	for (int i=0;i<=3*n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (i+2*j>3*n || (i+2*j)%3) continue;
			ans=(1ll*jc[3*n]*ipw2[j]%mod*ipw3[(3*n-i-2*j)/3]%mod*injc[i]%mod*injc[j]%mod*injc[(3*n-i-2*j)/3]%mod*pw[(3*n-i-2*j)/3]+ans)%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5,MOD=1e9+7;

long long fac[N],infac[N];

long long poww(long long x,long long y)
{
	if(y==0) return 1;
	if(y&1) return (x*poww(x,y-1))%MOD;
	return poww((x*x)%MOD,y/2);
}

long long nck(int n,int k)
{
	return (((fac[n]*infac[k])%MOD)*infac[n-k])%MOD;
}

long long get(int a,int b,int c,int d)
{
	int tot=(c-a)+(d-b);
	return nck(tot,c-a);
}

int main()
{
	fac[0]=infac[0]=1;
	for(int i=1;i<N;i++)
	{
		fac[i]=(fac[i-1]*i)%MOD;
		infac[i]=poww(fac[i],MOD-2);
	}
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	long long ans=0;
	for(int i=0;i<n-a;i++)
	{
		ans+=get(0,0,i,b-1)*get(i,b,n-1,m-1);
		ans%=MOD;
	}
	cout << ans << endl;
}
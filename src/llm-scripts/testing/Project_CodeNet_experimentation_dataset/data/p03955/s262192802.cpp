#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,a[4][N],f[N],g[N],w[N];
void biu()
{
	puts("No");
	exit(0);
}
void add(int x)
{
	for (int i=x;i<=n;i+=i&-i)
		w[i]++;
}
int qry(int x)
{
	int ans=0;
	for (int i=x;i;i-=i&-i)
		ans+=w[i];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=3;i++)
	for (int j=1;j<=n;j++)	
		scanf("%d",&a[i][j]);
	int s1=0,s2=0,a1=0,a2=0;
	for (int i=1;i<=n;i++)
	{
		if ((a[2][i]-2)%3) biu();
		f[i]=(a[2][i]+1)/3;
		if ((f[i]^i)&1) biu();
		if (a[1][i]==a[2][i]-1) g[i]=0;
		else if (a[1][i]==a[2][i]+1) g[i]=1;
		else biu();
		if (a[1][i]+a[3][i]!=a[2][i]*2) biu();
	}
	for (int i=n;i>=1;i-=2)
	{
		a1^=g[i];
		s1+=qry(f[i]);
		add(f[i]);
	}
	memset(w,0,sizeof w);
	for (int i=n-1;i>=1;i-=2)
	{
		a2^=g[i];
		s2+=qry(f[i]);
		add(f[i]);
	}
	if ((a2!=(s1&1))||(a1!=(s2&1))) biu();
	puts("Yes");
}
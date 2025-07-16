#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000010
#define N 2000010
#define P 1000000007
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,a[N],s[N],id[N],nxt[N],p[N],b[N],f[N][2],m,ans;
int ksm(int a,int k)
{
	int s=1;
	for (;k;k>>=1,a=1ll*a*a%P) if (k&1) s=1ll*s*a%P;
	return s; 
}
void inc(int &x,int y){x+=y;if (x>=P) x-=P;}
int solve(int x)
{
	if (p[x]<=n)
	{
		id[m=1]=p[x];
		while (nxt[id[m]]<=n) id[m+1]=nxt[id[m]],m++;
	}
	else return 0;
	int t=0;
	for (int i=1;i<=m;i++)
	{
		b[++t]=-1;
		if (i<m) b[++t]=s[id[i+1]]-s[id[i]];
	}
	f[0][0]=1;
	for (int i=1;i<=t;i++)
	{
		f[i][0]=f[i][1]=0;
		if (b[i]==-1)
		{
			f[i][0]=f[i-1][0];
			f[i][1]=(f[i-1][1]+f[i-1][0])%P;
		}
		else
		{
			f[i][1]=f[i-1][1];
			f[i][0]=(f[i-1][0]+1ll*f[i-1][1]*b[i])%P;
		}
	}
	return f[t][1];
}
int solve2(int x)
{
	if (p[x]<=n)
	{
		id[m=1]=p[x];
		while (nxt[id[m]]<n) id[m+1]=nxt[id[m]],m++;
	}
	else return 0;
	int t=0;id[m+1]=n;
	for (int i=1;i<=m;i++)
	{
		b[++t]=-1;
		b[++t]=s[id[i+1]]-s[id[i]];
	}
	f[0][0]=1;
	for (int i=1;i<=t;i++)
	{
		f[i][0]=f[i][1]=0;
		if (b[i]==-1)
		{
			f[i][0]=f[i-1][0];
			f[i][1]=(f[i-1][1]+f[i-1][0])%P;
		}
		else
		{
			f[i][1]=f[i-1][1];
			f[i][0]=(f[i-1][0]+1ll*f[i-1][1]*b[i])%P;
		}
	}
	return f[t][0];
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=a[i-1]^read();
	for (int i=1;i<=n;i++)
	{
		s[i]=s[i-1];
		if (a[i]==0) s[i]++;
	}
	for (int i=0;i<(1<<20);i++) p[i]=n+1;
	for (int i=n;i>=1;i--)
	{
		nxt[i]=p[a[i]];
		p[a[i]]=i;
	}
	if (a[n]==0)
	{
		ans=ksm(2,s[n]-1);
		for (int i=1;i<(1<<20);i++) inc(ans,solve(i));
	}
	else ans=solve2(a[n]);
	cout<<ans;
	return 0;
	//NOTICE LONG LONG!!!!!
}
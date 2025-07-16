#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=(1<<20)+5;
const int p=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int sum1[M],sum2[M],dp[N],s[N],x[N];

signed main()
{
	x[0]=s[0]=0;
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	int n=read();
	dp[0]=1;
	sum1[0]=1;
	for (int i=1;i<=n;i++)
	{
		x[i]=x[i-1]^read();
		s[i]=s[i-1]+(x[i]==0);
		dp[i]=((s[i-1]*sum1[x[i]]-sum2[x[i]]+1)%p+p)%p;
		add(sum1[x[i]],dp[i]);
		add(sum2[x[i]],dp[i]*s[i]%p);
	}
	if (x[n]) print(dp[n]);
	else
	{
		int ans=dp[n];
		for (int i=1;i<=n;i++) if (x[i]) add(ans,dp[i]);
		print(ans);
	}

	return 0;
}
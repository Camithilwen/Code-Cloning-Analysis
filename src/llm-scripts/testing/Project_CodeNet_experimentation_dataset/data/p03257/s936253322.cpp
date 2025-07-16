#include<bits/stdc++.h>
#define rg register
#define oo 0x7fffffff
#define ll long long
using namespace std;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		{
			fh=-1;
			jp=getchar();
		}
	while (jp>='0'&&jp<='9')
		{
			out=out*10+jp-'0';
			jp=getchar();
		}
	return out*fh;
}
const int MAXN=5e2+10;
const int MAXM=1e5+10;
int n;
ll Mat[MAXN][MAXN];
int pcnt=0,prime[MAXM],vis[MAXM];
void Linear_Shaker()
{
	for(rg int i=2;i<=MAXM;++i)
		{
			if(!vis[i])
				prime[++pcnt]=i;
			for(rg int j=1;i*prime[j]<=MAXM;++j)
				{
					vis[i*prime[j]]=1;
					if(i % prime[j]==0)
						break;
				}
		}
}
ll GCD(ll x,ll y)
{
	return y==0? x: GCD(y,x%y);
}
ll LCM(ll x,ll y)
{
	return x / GCD(x,y) * y;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	if(n==2)
		{
			printf("4 7\n23 10");
			return 0;
		}
	Linear_Shaker();
	for(rg int i=1;i<=n;++i)
		for(rg int j=1;j<=n;++j)
			Mat[i][j]=1ll;
	for(rg int i=1;i<=n;++i)
		for(rg int j=1;j<=n;++j)
			{
				if((i&1)==(j&1))
					{
						Mat[i][j]=1ll* prime[(i+j)/2] * prime[(i+n+1-j)/2+n];
						Mat[i+1][j]=LCM(Mat[i+1][j],Mat[i][j]);
						Mat[i-1][j]=LCM(Mat[i-1][j],Mat[i][j]);
						Mat[i][j+1]=LCM(Mat[i][j+1],Mat[i][j]);
						Mat[i][j-1]=LCM(Mat[i][j-1],Mat[i][j]);
					}
			}
	for(rg int i=1;i<=n;++i)
		for(rg int j=1;j<=n;++j)
			printf("%lld%c",(i&1)==(j&1)?Mat[i][j]:Mat[i][j]+1,j==n?'\n':' ');
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

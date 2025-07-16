#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n,m,q,ans;
int a[maxn][maxn],s[maxn][maxn],up[maxn][maxn],lf[maxn][maxn];
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>=48&&ch<=57){ret=ret*10+ch-48;ch=getchar();}
	return ret*f;
}
char fstchar()
{
	char ch=getchar();
	while(ch!='0'&&ch!='1') ch=getchar();
	return ch;
}
int main()
{
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=fstchar()-'0',s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		up[i][j]=up[i][j-1]+up[i-1][j]-up[i-1][j-1];
		lf[i][j]=lf[i-1][j]+lf[i][j-1]-lf[i-1][j-1];
		if(a[i][j]&&a[i-1][j]) up[i][j]++;
		if(a[i][j]&&a[i][j-1]) lf[i][j]++;
	}
	while(q--)
	{
		int x=read(),y=read(),xx=read(),yy=read();
		ans=s[xx][yy]-s[x-1][yy]-s[xx][y-1]+s[x-1][y-1];
		ans-=up[xx][yy]-up[x][yy]-up[xx][y-1]+up[x][y-1];
		ans-=lf[xx][yy]-lf[xx][y]-lf[x-1][yy]+lf[x-1][y];
		printf("%d\n",ans);
	}
	return 0;
}
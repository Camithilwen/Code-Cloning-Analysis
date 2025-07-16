#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3FFFFFFF
#define MN 2005
using namespace std;
int a[MN][MN],len[MN][MN],q[MN];
int n,m,p,ans,tp;
char c[MN];

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

int main()
{
	register int i,j;
	n=read(); m=read();
	for (i=1;i<=n;++i)
	{
		scanf("%s",c+1);
		for (j=1;j<=m;++j) a[i][j]=(c[j]=='#'?1:0);
	}
	for (i=1;i<n;++i)
		for (j=1;j<=m;++j) a[i][j]=a[i][j]^a[i+1][j];
	for (i=1;i<n;++i)
		for (j=1;j<m;++j) a[i][j]=a[i][j]^a[i][j+1];
	for (i=1;i<n;++i)
		for (j=1;j<m;++j)
			if (a[i][j]) len[i][j]=0;
			else len[i][j]=len[i-1][j]+1;
//	for (i=1;i<n;++i)
//		for (j=1;j<m;++j)	
	for (i=1;i<n;++i)
	{
		for (j=1;j<m;++j)
		{
			for (;tp&&len[i][j]<=len[i][q[tp]];--tp) ans=max(ans,(j-1-q[tp-1]+1)*(len[i][q[tp]]+1));
			q[++tp]=j;
		}
		for (;tp;--tp) ans=max(ans,(m-1-q[tp-1]+1)*(len[i][q[tp]]+1));
	}
	printf("%d",max(ans,n));
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace yspm{
	inline int read()
	{
		int res=0,f=1; char k;
		while(!isdigit(k=getchar())){if(k=='-') f=-1;}
		while(isdigit(k)){res=res*10+k-'0'; k=getchar();}
		return res*f;
	}
	const int N=2e3+10;
	int n,m,T,sum1[N][N],g[N][N];
	int lin[N][N],row[N][N],sum2[N][N];
	char s[N];
	signed main()
	{
		n=read(); m=read(); T=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s);
			for(int j=1;j<=m;++j) g[i][j]=s[j-1]-'0';
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1];
				sum2[i][j]=sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1];
				if(g[i][j]) ++sum2[i][j];
				row[i][j]=row[i][j-1]; lin[i][j]=lin[i-1][j];
				if(g[i][j])
				{
					if(g[i-1][j]) ++sum1[i][j],++row[i][j];
					if(g[i][j-1]) ++sum1[i][j],++lin[i][j];
				}
			}
		}
		int x1,y1,x2,y2;
		while(T--)
		{
			x1=read(); y1=read(); x2=read(); y2=read();
			int tmp=sum1[x2][y2]-sum1[x2][y1-1]-sum1[x1-1][y2]+sum1[x1-1][y1-1];
			tmp-=lin[x2][y1]-lin[x1-1][y1];
			tmp-=row[x1][y2]-row[x1][y1-1];
			int ans=sum2[x2][y2]-sum2[x2][y1-1]-sum2[x1-1][y2]+sum2[x1-1][y1-1]-tmp;
			printf("%lld\n",ans);
		}
		return 0;
	}
}
signed main()
{
	yspm::main();
	return 0;
}
#include<bits/stdc++.h>
#define MAXN 300005
#define MOD 1000000007
using namespace std;

int n;
char c[MAXN];
long long f[MAXN][4][4];
long long ans=0;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	register int i,x,y;
	scanf("%s",c+1);
	n=strlen(c+1);
	f[0][0][0]=1;
	for(i=1;i<=n;++i)
		for(x=0;x<=2;++x)
			for(y=0;y<=2;++y)
			{
				if(c[i]!='1')
				{
					if(y==2) f[i][x][y-1]=(f[i][x][y-1]+f[i-1][x][y])%MOD;
					else f[i][x][y+1]=(f[i][x][y+1]+f[i-1][x][y])%MOD;
				}
				if(c[i]!='0')
				{
					if(y==0) f[i][x+(x!=2)][y]=(f[i][x+(x!=2)][y]+f[i-1][x][y])%MOD;
					else f[i][x][y-1]=(f[i][x][y-1]+f[i-1][x][y])%MOD;
				}
			}
	for(x=0;x<=2;++x)
		for(y=x;y>=0;--y)
			ans=(ans+f[n][x][y])%MOD;
	printf("%lld",ans);
	return 0;
}
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
 
using namespace std;
const int N=17,M=40000,INF=1000000000;
int n,m,f[M],q[M],tot,dis[N][N],u,v,c,g[N][M];
 
int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}
 
int query1(int x)
{
	int rt=0;
	rep(i,1,n)
		if(x&(1<<i-1))
			rep(j,i+1,n)
				if(x&(1<<j-1) && dis[i][j]!=INF)
					rt+=dis[i][j];
	return rt;
}
 
int query2(int x,int y)
{
	int rt=0,maxn=0;
	rep(i,1,n)
		if(x&(1<<i-1))
			maxn=max(maxn,g[i][y]);
	return maxn;
}

int main()
{
	n=getint(),m=getint();
	rep(i,1,n) rep(j,1,n) dis[i][j]=i==j?0:INF;
	rep(i,1,m) u=getint(),v=getint(),dis[u][v]=dis[v][u]=c=getint(),tot+=c;
 	rep(i,1,n)
		rep(j,0,(1<<n)-1)
			rep(k,1,n)
				if(dis[i][k]!=INF && j&(1<<k-1))
					g[i][j]+=dis[i][k];
	rep(i,1,(1<<n)-1) f[i]=-INF;
	f[1]=0;
	rep(i,1,(1<<n)-2)
		if(f[i]!=-INF)
		{
			rep(j,1,n)
				if(!(i&(1<<j-1)))
				{
					int maxn=0;
					rep(k,1,n)
						if(i&(1<<k-1) && dis[j][k]!=INF)
							maxn=max(maxn,dis[j][k]);
					if(maxn) f[i|(1<<j-1)]=max(f[i|(1<<j-1)],f[i]+maxn);
				}
		}
	
	rep(i,1,(1<<n)-1)
	{
		if(!(i&1) || !(i&(1<<n-1))) f[i]=-INF;
		q[i]=query1(i);
	}
	
	rep(i,1,(1<<n)-1)
		if(f[i]!=-INF)
			for(int j=((1<<n)-1)^i; j; j=(j-1)&(((1<<n)-1)^i))
				f[i|j]=max(f[i|j],f[i]+q[j]+query2(i,j));
 
	printf("%d\n",tot-f[(1<<n)-1]);
	return 0;
}
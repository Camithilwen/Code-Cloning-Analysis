#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
#define N 100050
#define M 605
int n,d1,d2,head[N],cnt,col[M][M],col2[M][M],vis[M][M],ct,s1[N][2];
queue<int> tp;
void bfs(int x,int y)
{
	vis[x][y]=1;
	tp.push(x*1000+y);
	while(!tp.empty())
	{
		int s=tp.front()/1000,t=tp.front()%1000;tp.pop();
		for(int i=0;i<=ct;i++)
		for(int j=s-s1[i][0];j<=s+s1[i][0];j+=s1[i][0]*2)
		{
			for(int k=t-s1[i][1];k<=t+s1[i][1];k+=s1[i][1]*2)
			{
				if(j>=1&&j<=n&&k>=1&&k<=n&&!vis[j][k])vis[j][k]=1,col[j][k]=col[s][t]^1,tp.push(j*1000+k);
				if(!s1[i][1])break;
			}
			if(!s1[i][0])break;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&d1,&d2);n*=2;
	ct=0;for(int i=0;i<=n;i++)if(d1>=i*i){int tp=sqrt(d1-i*i);if(i*i+tp*tp==d1)s1[++ct][0]=i,s1[ct][1]=tp;}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(!vis[i][j])bfs(i,j);
	int tp=0;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)tp+=col[i][j]?-1:1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)col2[i][j]=col[i][j]^(tp>=0),vis[i][j]=0,col[i][j]=0;
	ct=0;for(int i=0;i<=n;i++)if(d2>=i*i){int tp=sqrt(d2-i*i);if(i*i+tp*tp==d2)s1[++ct][0]=i,s1[ct][1]=tp;}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(!vis[i][j])bfs(i,j);
	tp=0;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)tp+=col[i][j]?-1:1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)col[i][j]=col[i][j]^(tp>=0);
	int ct=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(ct<n*n/4&&col[i][j]==1&&col2[i][j]==1)printf("%d %d\n",i-1,j-1),ct++;
}
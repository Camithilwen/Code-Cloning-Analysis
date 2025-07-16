#include<cstdio>
#include<utility>
#include<iostream>
#define RI register int
#define CI const int&
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair <int,int> pi;
const int N=1005,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
inline char get_ch(void)
{
	char ch; while (ch=getchar(),ch!='#'&&ch!='.'); return ch;
}
int n,m,stp[N][N],ans; pi q[N*N];
int main()
{
	RI i,j,H=0,T=0; for (scanf("%d%d",&n,&m),i=1;i<=n;++i)
	for (j=1;j<=m;++j) if (get_ch()=='#') q[++T]=mp(i,j); else stp[i][j]=1e9;
	while (H<T)
	{
		int nx=q[++H].fi,ny=q[H].se; for (i=0;i<4;++i)
		{
			int tx=nx+dx[i],ty=ny+dy[i];
			if (tx>=1&&tx<=n&&ty>=1&&ty<=m&&stp[tx][ty]>stp[nx][ny]+1)
			stp[tx][ty]=stp[nx][ny]+1,q[++T]=mp(tx,ty);
		}
	}
	for (i=1;i<=n;++i) for (j=1;j<=m;++j) ans=max(ans,stp[i][j]);
	return printf("%d",ans),0;
}
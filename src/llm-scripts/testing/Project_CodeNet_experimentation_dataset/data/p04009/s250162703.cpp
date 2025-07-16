#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n,m,Ex,Ey,Ans,f[2][110][110][110];
int g[110][110],row[110][110],line[110][110];

inline int Row(int id,int L,int R) {return row[id][R]-row[id][L-1];}
inline int Line(int U,int D,int id) {return line[D][id]-line[U-1][id];}

int main()
{
//#ifdef h10
//	freopen("robots.in","r",stdin);
//	freopen("robots.out","w",stdout);
//#endif
	int i,j,U,D,L,R;
	char c;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
	{
		c=getchar();
		while (c!='.'&&c!='o'&&c!='E') c=getchar();
		if (c=='o') g[i][j]=1;
		if (c=='E') Ex=i,Ey=j;
		row[i][j]=row[i][j-1]+g[i][j];
		line[i][j]=line[i-1][j]+g[i][j];
	}
	for (U=0;U<Ex;U++)
	for (D=0;D<=n-Ex;D++)
	for (L=0;L<Ey;L++)
	for (R=0;R<=m-Ey;R++)
	{
		int X=U&1,Y=X^1,&val=f[X][D][L][R];
		int u=max(D+1,Ex-U),d=min(Ex+D,n-U);
		int l=max(R+1,Ey-L),r=min(Ey+R,m-L);
		if (U&&Ex-U-D>0) val=max(val,f[Y][D][L][R]+Row(Ex-U,l,r));
		if (D&&Ex+D+U<=n) val=max(val,f[X][D-1][L][R]+Row(Ex+D,l,r));
		if (L&&Ey-L-R>0) val=max(val,f[X][D][L-1][R]+Line(u,d,Ey-L));
		if (R&&Ey+R+L<=m) val=max(val,f[X][D][L][R-1]+Line(u,d,Ey+R));
		Ans=max(Ans,val);
	}
	printf("%d\n",Ans);
}

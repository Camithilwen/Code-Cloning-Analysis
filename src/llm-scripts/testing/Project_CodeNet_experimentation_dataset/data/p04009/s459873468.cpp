#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=101;
char a[N][N];
int row[N][N],col[N][N],f[N][N][N][N];
int n,m,x,y;

inline void chk(int &a,int b){a=max(a,b);}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=m;++j)
		{
			row[i][j]=row[i][j-1]+(a[i][j]=='o');
			col[i][j]=col[i-1][j]+(a[i][j]=='o');
			if(a[i][j]=='E') x=i,y=j;
		};
	int ans=0;
	for(int l=0;l<=y-1;++l)
		for(int r=0;r<=m-y;++r)
			for(int u=0;u<=x-1;++u)
				for(int d=0;d<=n-x;++d)
				{
					ans=max(ans,f[l][r][u][d]);
					int ub=max(x-u,1+d),db=min(x+d,n-u),lb=max(y-l,1+r),rb=min(y+r,m-l);
					int nx,ny;
					ny=y-l-1;
					if(1+r<=ny&&ny<=m-l) chk(f[l+1][r][u][d],f[l][r][u][d]+(db>=ub?(col[db][ny]-col[ub-1][ny]):0));
					ny=y+r+1;
					if(1+r<=ny&&ny<=m-l) chk(f[l][r+1][u][d],f[l][r][u][d]+(db>=ub?(col[db][ny]-col[ub-1][ny]):0));
					nx=x-u-1;
					if(1+d<=nx&&nx<=n-u) chk(f[l][r][u+1][d],f[l][r][u][d]+(rb>=lb?(row[nx][rb]-row[nx][lb-1]):0));
					nx=x+d+1;
					if(1+d<=nx&&nx<=n-u) chk(f[l][r][u][d+1],f[l][r][u][d]+(rb>=lb?(row[nx][rb]-row[nx][lb-1]):0));			
				};
	printf("%d\n",ans);
 	return 0;
}
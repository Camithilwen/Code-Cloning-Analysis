#include<iostream>
#include<cstdio>
#include<cstring>
namespace wohaocaia
{
	inline void check_max(int a,int &b){if(a>b)b=a;}
	const int N=105;
	int s[N][N],f[N][N][N][N];
	int n,m,sx,sy;
	int tl,tr,tu,td;
	int got(){for(char c=getchar();;c=getchar())if(c=='o' || c=='.' || c=='E')return c;}
	int min(int a,int b){return a<b?a:b;}
	int max(int a,int b){return a>b?a:b;}
	void initialize()
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				int x=got();
				if(x=='o')s[i][j]=1;
				else if(x=='.')s[i][j]=0;
				else sx=i,sy=j;
				s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			}
	}
	int bdy(int a,int b,int c,int d)
	{
		if(a>c || b>d)return 0;
//		printf("(%d,%d) -- (%d,%d) : %d\n",a,b,c,d,s[c][d]-s[c][b-1]-s[a-1][d]+s[a-1][b-1]);
		return s[c][d]-s[c][b-1]-s[a-1][d]+s[a-1][b-1];
	}
	void dp()
	{
		tl=sy-1,tr=m-sy,tu=sx-1,td=n-sx;

//		printf("L:%d , R:%d , U:%d , D:%d \n",tl,tr,tu,td);
//		printf("%d , %d \n",sx,sy);
		
		f[0][0][0][0]=0;
		for(int l=0;l<=tl;l++)
			for(int r=0;r<=tr;r++)
				for(int u=0;u<=tu;u++)
					for(int d=0;d<=td;d++)
					{
						int v=f[l][r][u][d];
						check_max(v+bdy(max(sx-u,d+1),sy-l-1,min(sx+d,n-u),sy-l-1)*(sy-l-1>r),f[l+1][r][u][d]);
						check_max(v+bdy(max(sx-u,d+1),sy+r+1,min(sx+d,n-u),sy+r+1)*(sy+r+1<=m-l),f[l][r+1][u][d]);

						check_max(v+bdy(sx-u-1,max(sy-l,r+1),sx-u-1,min(sy+r,m-l))*(sx-u-1>d),f[l][r][u+1][d]);
						check_max(v+bdy(sx+d+1,max(sy-l,r+1),sx+d+1,min(sy+r,m-l))*(sx+d+1<=n-u),f[l][r][u][d+1]);

//						printf("f[%d][%d][%d][%d] = %d\n",l,r,u,d,v);
					}
	}
	void orz()
	{
		initialize();
		dp();
		printf("%d\n",f[tl][tr][tu][td]);
	}
}
int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	wohaocaia::orz();
	return 0;
}

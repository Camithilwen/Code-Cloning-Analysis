#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iostream>
#define N 101
using namespace std;
short n,m,f[N][N][N][N],sx,sy,h[N][N],L[N][N];
char s[N][N];
void upd(short &x,short y)
{
	if(x<y) x=y;
}
int main()
{
	cin>>n>>m;
	for(short i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(short j=1;j<=m;j++) if(s[i][j]=='E') sx=i,sy=j;
	}
	for(short i=1;i<=n;i++)
		for(short j=1;j<=m;j++)
		{
			L[i][j]=L[i-1][j];
			h[i][j]=h[i][j-1];
			if(s[i][j]=='o') h[i][j]++,L[i][j]++;
		}
	short ln=m-sy,rn=sy-1,un=n-sx,dn=sx-1;
	for(short i=0;i<=ln;i++)
		for(short j=0;j<=rn;j++)
			for(short x=0;x<=un;x++)
				for(short y=0;y<=dn;y++)
				{
					short t,now,l,r;
					if(i<ln)
					{
						now=sy+i+1;t=0;
						if(now+j<=m)
						{
							l=max(sx-y,x+1);r=min(sx+x,n-y);
							if(l<=r) t=L[r][now]-L[l-1][now];
						}
						upd(f[i+1][j][x][y],f[i][j][x][y]+t);
					}
					if(j<rn)
					{
						now=sy-j-1;t=0;
						if(now-i>=1)
						{
							l=max(sx-y,x+1);r=min(sx+x,n-y);
							if(l<=r) t=L[r][now]-L[l-1][now];
						}
						upd(f[i][j+1][x][y],f[i][j][x][y]+t);
					}
					if(i==1 && j==0 && x==0 && y==1)
					{short oo=1;}
					if(x<un)
					{
						now=sx+x+1;t=0;
						if(now+y<=n)
						{
							l=max(sy-j,i+1);r=min(sy+i,m-j);
							if(l<=r) t=h[now][r]-h[now][l-1];
						}
						upd(f[i][j][x+1][y],f[i][j][x][y]+t);
					}
					if(y<dn)
					{
						now=sx-y-1;t=0;
						if(now-x>=1)
						{
							l=max(sy-j,i+1);r=min(sy+i,m-j);
							if(l<=r) t=h[now][r]-h[now][l-1];
						}
						upd(f[i][j][x][y+1],f[i][j][x][y]+t);
					}
					if(f[1][0][1][1]==4)
					{short oo=1;}
				}
	cout<<f[ln][rn][un][dn]<<endl;
	return 0;
}
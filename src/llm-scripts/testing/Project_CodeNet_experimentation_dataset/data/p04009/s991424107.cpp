#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,k,l,x,y;
short f[105][105][105][105],ans,s1[105][105],s2[105][105],z;
char s[105][105];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;++j)
		{
			s1[i][j]=s1[i][j-1]+(s[i][j]=='o'?1:0);
			if(s[i][j]=='E')
				x=i,y=j;
		}
	}
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			s2[i][j]=s2[i][j-1]+(s[j][i]=='o'?1:0);
	f[0][0][0][0]=0;
	for(i=0;i<x;++i)
		for(j=0;j<=n-x;++j)
			for(k=0;k<y;++k)
				for(l=0;l<=m-y;++l)
				{
					ans=max(ans,f[i][j][k][l]);
					int lx=j+1,rx=n-i,ly=l+1,ry=m-k;
					//printf("%d %d %d %d  %d   %d %d %d %d\n",i,j,k,l,f[i][j][k][l],lx,rx,ly,ry);
					if(i+1<x)
						f[i+1][j][k][l]=max((int)f[i+1][j][k][l],f[i][j][k][l]+(x-i-1>=lx&&x-i-1<=rx?s1[x-i-1][min(y+l,ry)]-s1[x-i-1][max(y-k,ly)-1]:0));
					if(j+1<=n-x)
						f[i][j+1][k][l]=max((int)f[i][j+1][k][l],f[i][j][k][l]+(x+j+1>=lx&&x+j+1<=rx?s1[x+j+1][min(y+l,ry)]-s1[x+j+1][max(y-k,ly)-1]:0));
					if(k+1<y)
						f[i][j][k+1][l]=max((int)f[i][j][k+1][l],f[i][j][k][l]+(y-k-1>=ly&&y-k-1<=ry?s2[y-k-1][min(x+j,rx)]-s2[y-k-1][max(x-i,lx)-1]:0));
					if(l+1<=m-y)
						f[i][j][k][l+1]=max((int)f[i][j][k][l+1],f[i][j][k][l]+(y+l+1>=ly&&y+l+1<=ry?s2[y+l+1][min(x+j,rx)]-s2[y+l+1][max(x-i,lx)-1]:0));
				}
	printf("%hd",ans);
	return 0;
}

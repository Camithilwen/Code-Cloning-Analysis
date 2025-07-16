#include<bits/stdc++.h>
using namespace std;
#define RI register int
const int N=105;
char mp[N][N];
int f[2][N][N][N],a[N][N],n,m,sx,sy,ans;
int gets(int x1,int y1,int x2,int y2)
	{return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];}
int main()
{
	scanf("%d%d",&n,&m);
	for(RI i=1;i<=n;++i) {
		scanf("%s",mp[i]+1);
		for(RI j=1;j<=m;++j) {
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(mp[i][j]=='o');
			if(mp[i][j]=='E') sx=i,sy=j;
		}
	}
	for(RI x1=0,t=0;x1<sx;++x1,t^=1)
	  for(RI y1=0;y1<sy;++y1)
	    for(RI x2=0;x2<=n-sx;++x2)
	      for(RI y2=0;y2<=m-sy;++y2) {
	      	if(x1&&sx-x1>x2)
	      		f[t][y1][x2][y2]=max(f[t][y1][x2][y2],f[t^1][y1][x2][y2]+
	      			gets(sx-x1,max(sy-y1,y2+1),sx-x1,min(sy+y2,m-y1)));
	      	if(y1&&sy-y1>y2)
	      		f[t][y1][x2][y2]=max(f[t][y1][x2][y2],f[t][y1-1][x2][y2]+
	      			gets(max(sx-x1,x2+1),sy-y1,min(sx+x2,n-x1),sy-y1));
	      	if(x2<n&&sx+x2<=n-x1)
	      		f[t][y1][x2][y2]=max(f[t][y1][x2][y2],f[t][y1][x2-1][y2]+
	      			gets(sx+x2,max(sy-y1,y2+1),sx+x2,min(sy+y2,m-y1)));
	      	if(y2<m&&sy+y2<=m-y1)
	      		f[t][y1][x2][y2]=max(f[t][y1][x2][y2],f[t][y1][x2][y2-1]+
	      			gets(max(sx-x1,x2+1),sy+y2,min(sx+x2,n-x1),sy+y2));
	      	ans=max(ans,f[t][y1][x2][y2]);
	      }
	printf("%d\n",ans); 
	return 0;
}
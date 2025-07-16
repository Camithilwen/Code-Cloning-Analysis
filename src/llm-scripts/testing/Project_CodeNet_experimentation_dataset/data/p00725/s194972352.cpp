#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int ans;
int f[25][25];
int w,h,sx,sy,gx,gy;
void dfs(int x,int y,int turn)
{
	if(turn>10||turn>=ans)return;
	for(int i=y+1;i<w;i++)
	{
		if(x==gx&&i==gy)
		{
			ans=min(ans,turn);
			return;
		}
		if(f[x][i]==1)
		{
			if(i==y+1)break;
			f[x][i]=0;
			dfs(x,i-1,turn+1);
			f[x][i]=1;
			break;
		}
	}
	for(int i=y-1;i>=0;i--)
	{
		if(x==gx&&i==gy)
		{
			ans=min(ans,turn);
			return;
		}
		if(f[x][i]==1)
		{
			if(i==y-1)break;
			f[x][i]=0;
			dfs(x,i+1,turn+1);
			f[x][i]=1;
			break;
		}
	}
	for(int i=x+1;i<h;i++)
	{
		if(gx==i&&gy==y)
		{
			ans=min(ans,turn);
			return;
		}
		if(f[i][y]==1)
		{
			if(i==x+1)break;
			f[i][y]=0;
			dfs(i-1,y,turn+1);
			f[i][y]=1;
			break;
		}
	}
	for(int i=x-1;i>=0;i--)
	{
		if(gx==i&&gy==y)
		{
			ans=min(ans,turn);
			return;
		}
		if(f[i][y]==1)
		{
			if(i==x-1)break;
			f[i][y]=0;
			dfs(i+1,y,turn+1);
			f[i][y]=1;
			break;
		}
	}
	return;
}
int main()
{
	while(1)
	{
		ans=100;
		memset(f,0,sizeof(f));
		scanf("%d %d",&w,&h);
		if(w==0&&h==0)break;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				scanf("%d",&f[i][j]);
				if(f[i][j]==2)
				{
					sx=i;sy=j;
					f[i][j]=0;
				}
				if(f[i][j]==3)
				{
					gx=i;gy=j;
					f[i][j]=0;
				}
			}
		}
		dfs(sx,sy,1);
		if(ans==100)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
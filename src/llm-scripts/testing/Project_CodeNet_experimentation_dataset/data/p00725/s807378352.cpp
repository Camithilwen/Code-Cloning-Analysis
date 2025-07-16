#include<iostream>
using namespace std;
int h,w,map[20][20];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int f(int i,int j,int cnt)
{
	if(cnt>10)return 11;
	int ans=11;
	for(int r=0;r<4;r++)
	{
		int x=i+dx[r],y=j+dy[r];
		while(x>=0&&y>=0&&x<h&&y<w&&map[x][y]==0)x+=dx[r],y+=dy[r];
		if(x<0||y<0||x>=h||y>=w)continue;
		else if(map[x][y]==3)return cnt+1;
		else
		{
			map[x][y]=0;
			if(x-dx[r]!=i||y-dy[r]!=j)ans=min(ans,f(x-dx[r],y-dy[r],cnt+1));
			map[x][y]=1;
		}
	}
	return ans;
}
main()
{
	while(cin>>w>>h,h)
	{
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>map[i][j];
		int sx,sy;
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)
		{
			if(map[i][j]==2)
			{
				sx=i;sy=j;map[i][j]=0;
			}
		}
		int t=f(sx,sy,0);
		cout<<(t>10?-1:t)<<endl;
	}
}


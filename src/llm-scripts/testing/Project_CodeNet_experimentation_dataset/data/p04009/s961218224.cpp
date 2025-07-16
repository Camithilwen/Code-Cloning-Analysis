#include <bits/stdc++.h>

using namespace std;

const int N=110;

int h,w,px,py,f[N][N][N][N],col[N][N],row[N][N];
bool mp[N][N];

void Init()
{
	scanf("%d%d",&h,&w);
	for (int i=1;i<=h;++i)
		for (int j=1;j<=w;++j)
		{
			char ch=getchar();
			while (ch!='o' && ch!='.' && ch!='E') ch=getchar();
			if (ch=='E') px=i,py=j;
			if (ch=='o') mp[i][j]=1;
			else mp[i][j]=0;
		}
}

int Col(int r,int l,int x)
{
	if (l>r) return 0;
	return col[r][x]-col[l][x];
}

int Row(int r,int l,int x)
{
	if (l>r) return 0;
	return row[x][r]-row[x][l];
}

void Solve()
{
	
	for (int i=1;i<=h;++i)
		for (int j=1;j<=w;++j)
		{
			col[i][j]=col[i-1][j]+mp[i][j];
			row[i][j]=row[i][j-1]+mp[i][j];
		}
	int ans=0;
	for (int a=px;a>0;--a)
		for (int b=px;b<=h;++b)
			for (int c=py;c>0;--c)
				for (int d=py;d<=w;++d) f[a][b][c][d]=-1e9;
	f[px][px][py][py]=0;
	for (int a=px;a>0;--a)
		for (int b=px;b<=h;++b)
			for (int c=py;c>0;--c)
				for (int d=py;d<=w;++d)
				{
					if (a>1 && a-1>b-px) 
						f[a-1][b][c][d]=max(f[a-1][b][c][d],f[a][b][c][d]+Row(min(w-(py-c),d),max(c-1,d-py),a-1));
					if (b<h && h-b>px-a) 
						f[a][b+1][c][d]=max(f[a][b+1][c][d],f[a][b][c][d]+Row(min(w-(py-c),d),max(c-1,d-py),b+1));
					if (c>1 && c-1>d-py) 
						f[a][b][c-1][d]=max(f[a][b][c-1][d],f[a][b][c][d]+Col(min(h-(px-a),b),max(a-1,b-px),c-1));
					if (d<w && w-d>py-c) 
						f[a][b][c][d+1]=max(f[a][b][c][d+1],f[a][b][c][d]+Col(min(h-(px-a),b),max(a-1,b-px),d+1));
					ans=max(ans,f[a][b][c][d]);
				}
	
	printf("%d\n",ans);
}

int main()
{
	Init();
	Solve();
	return 0;
}
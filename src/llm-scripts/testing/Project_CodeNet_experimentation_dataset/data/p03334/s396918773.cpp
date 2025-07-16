#include <bits/stdc++.h>

using namespace std;

int n,d1,d2;
int col[603][603],col1[605][605],col2[605][605];
int dx[4803],dy[4803],cnt;
vector<pair<int,int> > typ[2][2];

void Col(int x,int y,int tar)
{
	col[x][y] = tar;
	for(int i = 1;i <= cnt; ++ i)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && !col[nx][ny])
			Col(nx,ny,tar ^ 1);
	}
}

int main()
{
	scanf("%d%d%d",&n,&d1,&d2);
	n *= 2;
	for(int i = 0;i <= n; ++ i)
		for(int j = i;j <= n; ++ j)
			if(i * i + j * j == d1)
			{
				dx[++ cnt] = i; dy[cnt] = j;
				dx[++ cnt] = j; dy[cnt] = i;
				dx[++ cnt] = -i; dy[cnt] = -j;
				dx[++ cnt] = -j; dy[cnt] = -i;
				dx[++ cnt] = i; dy[cnt] = -j;
				dx[++ cnt] = j; dy[cnt] = -i;
				dx[++ cnt] = -i; dy[cnt] = j;
				dx[++ cnt] = -j; dy[cnt] = i;
			}
	for(int i = 1;i <= n; ++ i)
		for(int j = 1;j <= n; ++ j)
		{
			if(!col[i][j])
				Col(i,j,2);
			col1[i][j] = col[i][j] - 2;
		}
	cnt = 0;
	for(int i = 0;i <= n; ++ i)
		for(int j = i;j <= n; ++ j)
			if(i * i + j * j == d2)
			{
				dx[++ cnt] = i; dy[cnt] = j;
				dx[++ cnt] = j; dy[cnt] = i;
				dx[++ cnt] = -i; dy[cnt] = -j;
				dx[++ cnt] = -j; dy[cnt] = -i;
				dx[++ cnt] = i; dy[cnt] = -j;
				dx[++ cnt] = j; dy[cnt] = -i;
				dx[++ cnt] = -i; dy[cnt] = j;
				dx[++ cnt] = -j; dy[cnt] = i;
			}
	memset(col,0,sizeof(col));
	for(int i = 1;i <= n; ++ i)
		for(int j = 1;j <= n; ++ j)
		{
			if(!col[i][j])
				Col(i,j,2);
			col2[i][j] = col[i][j] - 2;
			typ[col1[i][j]][col2[i][j]].push_back(make_pair(i,j));
		}
	for(int i = 0;i < 2; ++ i)
		for(int j = 0;j < 2; ++ j)
			if(typ[i][j].size() >= n * n / 4)
			{
				for(int k = 0;k < n * n / 4; ++ k)
					printf("%d %d\n",typ[i][j][k].first - 1,typ[i][j][k].second - 1);
				return 0;
			}
	return 0;
}
#include <bits/stdc++.h> 
 
using namespace std; 

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
char board[401][401];
int h,w;
int visited[401][401];
long long int arr[160005][2];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> h >> w;

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> board[i][j];
		}
	}

	memset(visited,-1,sizeof(visited));

	int cnt = 0;

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(visited[i][j]==-1 && board[i][j]=='#')
			{
				queue <pair<int,int>> que;
				que.push(make_pair(i,j));
				visited[i][j] = cnt;
				while(!que.empty())
				{
					int y = que.front().first;
					int x = que.front().second;
					que.pop();

					for(int k=0;k<4;k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];
						if(ny < 0 || ny >= h || nx < 0 || nx >= w)
						{
							continue;
						}
						if(visited[ny][nx]==-1 && board[ny][nx]!=board[y][x])
						{
							visited[ny][nx] = cnt;
							que.push(make_pair(ny,nx));
						}
					}
				}
				cnt++;
			}
		}
	}

	long long int res = 0;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(visited[i][j]==-1)
			{
				continue;
			}
			if(board[i][j]=='#')
			{
				arr[visited[i][j]][0]++;
			}
			else
			{
				arr[visited[i][j]][1]++;
			}
		}
	}

	for(int i=0;i<cnt;i++)
	{
		res += (arr[i][0]*arr[i][1]);
	}

	cout << res << '\n';

    return 0;
}
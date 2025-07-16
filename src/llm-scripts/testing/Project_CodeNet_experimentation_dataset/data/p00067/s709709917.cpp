#include <iostream>
#include <string>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

string s[12];
int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1};

void dfs(int x,int y)
{
	s[x][y] = '0';

	rep(i,4)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(0 <= nx && nx < 12 && 0 <= ny && ny < 12)
		{
			if(s[nx][ny] == '1')
			{
				dfs(nx,ny);
			}
		}
	}
	return;
}


int main()
{
	while(cin >> s[0])
	{
		REP(i,1,12)
		{
			cin >> s[i];
		}

		int res = 0;
		rep(i,12)
		{
			rep(j,12)
			{
				if(s[i][j] == '1')
				{
					dfs(i,j);
					res++;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
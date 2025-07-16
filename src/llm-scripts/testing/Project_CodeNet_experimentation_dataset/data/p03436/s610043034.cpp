#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char c[55][55];
bool visited[55][55];
int d[55][55];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
queue<P> Q;

int main()
{
	int H,W;
	cin >> H >> W;
	int cntW = 0;
	rep(i,H)
	{
		rep(j,W)
		{
			cin >> c[i][j];
			if (c[i][j] == '.') cntW++;
		}
	}
	rep(i,55)
	{
		rep(j,55)
		{
			d[i][j] = 1e8;
		}
	}
	d[0][0] = 0;
	Q.push(P(0,0));
	while(!Q.empty())
	{
		P q = Q.front();
		int f = q.first, s = q.second;
		Q.pop();
		if (visited[f][s]) continue;
		visited[f][s] = true;
		rep(i,4)
		{
			int xx = f+dx[i], yy = s+dy[i];
			if (xx >= 0 && xx < H && yy >= 0 && yy < W && c[xx][yy] == '.')
			{
				d[xx][yy] = min(d[xx][yy],d[f][s]+1);
				Q.push(P(xx,yy));
			}
		}
	}
	/*
	rep(i,H)
	{
		rep(j,W)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	*/
	if (d[H-1][W-1] == 1e8) cout << -1 << endl;
	else cout << cntW - d[H-1][W-1] - 1 << endl;
	return 0;
}
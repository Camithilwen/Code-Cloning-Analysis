#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
char m[50][50]; 
int dist[100][100];
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main() {
	int h,w;
	cin >> h >> w;
	int numOfW = 0;
	rep(i,h) rep(j,w) {
		cin >> m[i][j];
		if (m[i][j] == '.') numOfW++;
	}

	rep(i,h) rep(j,w) dist[i][j] = -1;
	queue<P> q;
	q.push({0,0});
	dist[0][0] = 1;

	while (!q.empty())
	{
		P p = q.front(); q.pop();
		int x = p.first, y = p.second;
		rep(i,4) {
			int nx = x+dx[i], ny = y+dy[i];
			if (nx<0||nx>=h||nx<0||ny>=w) continue;
			if (m[nx][ny]=='#'||dist[nx][ny]!=-1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx,ny});
		}
	}
	
	if (dist[h-1][w-1] == -1) cout << -1 << endl;
	else cout << numOfW - dist[h-1][w-1] << endl;
	


	return 0;
}
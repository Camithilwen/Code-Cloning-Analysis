#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int N = 1010;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int _w;

int n, m;
char str[N][N];
int dis[N][N];
queue<pii> q;

bool inside( int x, int y ) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
	_w = scanf( "%d%d", &n, &m );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%s", str[i]+1 );
	memset(dis, -1, sizeof dis);
	for( int i = 1; i <= n; ++i )
		for( int j = 1; j <= m; ++j )
			if( str[i][j] == '#' )
				dis[i][j] = 0, q.push( pii(i, j) );
	int ans = 0;
	while( !q.empty() ) {
		pii now = q.front(); q.pop();
		ans = max(ans, dis[now.first][now.second]);
		for( int i = 0; i < 4; ++i ) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if( inside(nx, ny) && dis[nx][ny] == -1 ) {
				dis[nx][ny] = dis[now.first][now.second] + 1;
				q.push( pii(nx, ny) );
			}
		}
	}
	cout << ans << endl;
	return 0;
}

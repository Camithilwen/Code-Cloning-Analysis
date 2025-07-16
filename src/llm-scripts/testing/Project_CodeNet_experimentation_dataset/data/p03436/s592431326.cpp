#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> S;
int black = 0;
int white = 0;
int INF = 1001001001;

int main() {
	 int H, W;
	 cin >> H >> W;
	 for(int i = 0; i < H; ++i) {
		 string s;
		 cin >> s;
		 S.push_back(s);
	 }

	 for(int i = 0; i < H; ++i) {
		 for(int j = 0; j < W; ++j) {
			 if(S[i][j] == '#') ++black;
			 else ++white;
		 }
	 }

	 int dx[] = {1, 0, -1, 0};
	 int dy[] = {0, 1, 0, -1};

	 int dist[100][100];
	 queue<pair<int, int>> Q;
	 Q.push(make_pair(0, 0));

	 for(int i = 0; i < 100; ++i) {
		 for(int j = 0; j < 100; ++j) {
			 dist[i][j] = INF;
		 }
	 }

	 dist[0][0] = 0;

	 while(Q.size()) {
		 auto q = Q.front(); Q.pop();
		 if(q.first == W -1 && q.second == H -1) break;
		 for(int i = 0; i < 4; ++i) {
			 int nx = q.first + dx[i];
			 int ny = q.second + dy[i];

			 if(0 <= nx && nx < W && 0 <= ny && ny < H && S[ny][nx] != '#' && dist[nx][ny] == INF) {
				 Q.push(make_pair(nx, ny));
				 dist[nx][ny] = dist[q.first][q.second] + 1;
			 }
		 }
	 }
	 int g  = dist[W-1][H-1];
	 if(g == INF) {
		 cout << -1 << endl;
		 return 0;
	 }
	 cout << white - g -1  << endl;

	return 0;
}

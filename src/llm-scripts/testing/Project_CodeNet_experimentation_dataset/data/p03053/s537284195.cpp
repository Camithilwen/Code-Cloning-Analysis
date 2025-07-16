#include <bits/stdc++.h>
#define REP(i,n) for (int i=0; i<(n); ++i)
#define REPR(i,n,m) for (int i=(n); i>=(m); --i)
using namespace std;
using LL = long long;
using LD = long double;
using PLL = pair<long long, long long>;
using PLD = pair<long double, long double>;
using VLL = vector<long long>;
using VLD = vector<long double>;
using VPLL = vector<PLL>;
using VPLD = vector<PLD>;

const int INF = numeric_limits<int>::max();
const unsigned long long int ULLINF = numeric_limits<unsigned long long int>::max();

int main(){
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

	int h, w;
    cin >> h >> w;
    vector<string> v(h);
    for (int i=0; i<h; i++) cin >> v[i];

    // 多点スタート
    vector<vector<int>> dist(h, vector<int>(w, -1));
    using pint = pair<int, int>;
    queue<pint> que;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (v[i][j]=='#') {
                dist[i][j] = 0;
                que.push(pint(i,j));
            }
        }
    }

    // bfs
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >=h || ny < 0 || ny >= w) continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                que.push(pint(nx,ny));
            }
        }
    }

    int res = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            res = max(res, dist[i][j]);
        }
    }

    cout << res << endl;


	return 0;
}

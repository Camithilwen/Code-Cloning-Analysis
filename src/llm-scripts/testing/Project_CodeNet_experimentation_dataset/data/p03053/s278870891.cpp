#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int H, W;
vector<string> fi;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> H >> W;
    fi.resize(H);
    for (int i = 0; i < H; ++i) cin >> fi[i];

    // 多点をスタートとして扱う
    vector<vector<int> > dist(H, vector<int>(W, -1));
    using pint = pair<int,int>;
    queue<pint> que;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (fi[i][j] == '#') {
                dist[i][j] = 0;
                que.push(pint(i, j));
            }
        }
    }

    // BFS
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                que.push(pint(nx, ny));
            }
        }
    }
    int res = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            res = max(res, dist[i][j]);
        }
    }
    cout << res << endl;
}
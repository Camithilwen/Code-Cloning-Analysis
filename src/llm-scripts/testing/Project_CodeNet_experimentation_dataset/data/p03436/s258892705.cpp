#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> G(H);
    rep(i, H) cin >> G[i];

    int cnt = 0;
    rep(i, H) rep(j, W) {
        if (G[i][j] == '#') { cnt++; }
    }

    vector<vector<lint>> dist(H, vector<lint>(W, LINF));
    dist[0][0] = 0;
    queue<pair<int, int>> q({{0, 0}});
    while (!q.empty()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && G[nx][ny] == '.' &&
                dist[nx][ny] == LINF) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    // ddump(G);
    // ddump(dist);

    if (dist[H - 1][W - 1] == LINF) {
        cout << -1 << endl;
    } else {

        cout << (H * W - cnt) - (dist[H - 1][W - 1] + 1) << endl;
    }

    return 0;
}
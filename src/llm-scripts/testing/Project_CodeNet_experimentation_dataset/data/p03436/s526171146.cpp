#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> Graph(H);
    rep(i,H) cin >> Graph.at(i);

    vector<vector<int>> dist(H, vector<int>(W, -1)); // -1: 未訪問
    dist[0][0] = 0;

    int ans = -1;
    int wall = 0;
    rep(i,H) rep(j,W) if (Graph.at(i).at(j) == '#') ++wall;


    vector<string> G = Graph;
    vector<vector<int>> reached = dist;
    queue<P> que;

    que.push(make_pair(0, 0));
    dist[0][0] = 0;

    while (!que.empty()) {
        P p = que.front();
        que.pop();
        for (int direction = 0; direction < 4; ++direction) {
            int nh = p.first + dx[direction];
            int nw = p.second + dy[direction];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (dist.at(nh).at(nw) > -1) continue;
            if (Graph.at(nh).at(nw) == '#') continue;
            dist.at(nh).at(nw) = dist.at(p.first).at(p.second) + 1;
            if (nh == H - 1 && nw == W - 1) {
                ans = dist.at(nh).at(nw);
                break;
            }
            que.push(make_pair(nh, nw));
        }
    }
    if (ans == -1) cout << ans << endl;
    else 
    cout << H * W - wall - (ans + 1) << endl;
}

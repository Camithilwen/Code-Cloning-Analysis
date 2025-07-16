/*
    Problem 33
    https://atcoder.jp/contests/abc088/tasks/abc088_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
/* function */
/* main */
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> grid(h, vector<bool>(w));
    int ans = h * w;
    for (int i = 0; i < h*w; i++) {
        char c; cin >> c;
        grid[i/w][i%w] = c == '.';
        ans -= (c == '#');  // 黒マスの分あらかじめ引いとく
    }

    vector<vector<int>> dist(h, vector<int>(w, 0));
    queue<pii> q;
    q.emplace(0, 0);
    dist[0][0] = 1;
    while(!q.empty()) {
        pii p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < dx.size(); i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
            if (!grid[nx][ny] || dist[nx][ny] != 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
    cout << ((dist[h-1][w-1] == 0) ? -1 : ans - dist[h-1][w-1]) << '\n';
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int H, W; cin >> H >> W;
    vector<vc> S(H, vc(W));
    int cnt = 0;
    rep(i, H) {
        rep(j, W) {
            cin >> S[i][j];
            if (S[i][j] == '.') cnt++;
        }
    }

    vector<vi> mp = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vi> route(H, vi(W, INF));
    route[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        
        int ux = p.first; int uy = p.second;

        if (S[ux][uy] == '#') continue;
        S[ux][uy] = '#';

        for (int i = 0; i < 4; i++) {
            int vx = ux + mp[i][0];
            int vy = uy + mp[i][1];
            if (vx >= 0 && vx < H && vy >= 0 && vy < W && S[vx][vy] != '#') {
                q.push(make_pair(vx, vy));
                route[vx][vy] = min(route[vx][vy], route[ux][uy] + 1);
            }
        }
    }

    if (S[H - 1][W - 1] == '.') {
        cout << -1 << endl;
    } else {
        int d = route[H - 1][W - 1];
        cout << (cnt - d) << endl;
    }
}

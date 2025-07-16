#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int H, W;
    cin >> H >> W;
    int cnt = 0;
    vector<vector<char>> G(H, vector<char>(W));
    vector<pint> flip;
    rep(i, H) {
        rep(j, W) {
            cin >> G[i][j];
            if (G[i][j] == '.')
                cnt++;
            else
                flip.push_back({i, j});
        }
    }

    ll ans = 0;
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    while (cnt != 0) {
        vector<pint> A;
        rep(i, flip.size()) {
            for (int j = 0; j < 4; j++) {
                pint p = flip[i];
                int ny = p.first + dy[j];
                int nx = p.second + dx[j];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                    continue;
                if (G[ny][nx] == '#')
                    continue;
                G[ny][nx] = '#', cnt--, A.push_back({ny, nx});
            }
        }
        ans++;
        flip = A;
    }

    cout << ans << endl;
    return 0;
}
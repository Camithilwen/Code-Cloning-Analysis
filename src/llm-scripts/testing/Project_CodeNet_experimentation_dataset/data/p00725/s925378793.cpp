#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> TUPLE;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;

const int INF = 1e9;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int H, W;
int a[20][20];
int ans;

bool inside(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

void dfs(int x, int y, int c) {
    if (c > 10) return;

    rep(k, 4) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!inside(nx, ny)) continue;
        if (a[nx][ny] == 1) continue;
        while (true) {
            if (!inside(nx, ny)) break;
            if (a[nx][ny] == 1) {
                a[nx][ny] = 0;
                dfs(nx - dx[k], ny - dy[k], c + 1);
                a[nx][ny] = 1;
                break;
            }
            else if (a[nx][ny] == 3) {
                ans = min(ans, c);
                break;
            }

            nx += dx[k], ny += dy[k];
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (cin >> W >> H, H) {
        int sx, sy;
        rep(i, H) rep(j, W) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                sx = i, sy = j;
            }
        }

        ans = INF;
        dfs(sx, sy, 1);

        cout << (ans == INF ? -1 : ans) << endl;
    }
}
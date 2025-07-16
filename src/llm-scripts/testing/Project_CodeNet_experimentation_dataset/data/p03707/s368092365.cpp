#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int rcount[2001][2001], d[2001][2001], u[2001][2001], r[2001][2001], l[2001][2001];

int main() {
    int n, m, q; cin >> n >> m >> q;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++) {
            if (s[x-1][y-1] != '1') continue;
            rcount[x][y] = 1;
            queue<pair<int, int> > q;
            q.push({x, y});
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                s[i-1][j-1] = '2';
                const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
                for (int k = 0; k < 4; k++) {
                    int i1 = i + dx[k], j1 = j + dy[k];
                    if (0 < i1 && 0 < j1 && i1 <= n && j1 <= m && s[i1-1][j1-1] == '1') {
                        q.push({i1, j1});
                        if (i1 < i) u[i1][j] = 1;
                        else if (i1 > i) d[i1][j] = 1;
                        else if (j1 < j) l[i][j1] = 1;
                        else /* j1 > j */ r[i][j1] = 1;
                    }
                }
            }
        }
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++) {
            rcount[x][y] += rcount[x-1][y] + rcount[x][y-1] - rcount[x-1][y-1];
            d[x][y] += d[x][y-1];
            u[x][y] += u[x][y-1];
            r[x][y] += r[x-1][y];
            l[x][y] += l[x-1][y];
        }

    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int ans = rcount[x2][y2] - rcount[x1-1][y2] - rcount[x2][y1-1] + rcount[x1-1][y1-1];
        ans += r[x2][y1] - r[x1-1][y1];
        ans += l[x2][y2] - l[x1-1][y2];
        ans += d[x1][y2] - d[x1][y1-1];
        ans += u[x2][y2] - u[x2][y1-1];
        cout << ans << endl;
    }
}

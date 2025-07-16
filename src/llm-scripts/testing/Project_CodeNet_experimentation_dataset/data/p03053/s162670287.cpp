#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, m;

bool vis[1005][1005];
char s[1005];
int dist[1005][1005];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    scanf("%d%d", &n, &m);
    queue<pair<int, int> > bfs;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            if (s[j] == '#') {
                bfs.push(make_pair(i, j));
                vis[i][j] = true;
            }
        }
    }
    while (!bfs.empty()) {
        pair<int, int> cur = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> newpos = make_pair(cur.first
                + dx[i], cur.second + dy[i]);
            if (newpos.first < 1 || newpos.first > n ||
                newpos.second < 1 || newpos.second > m) continue;
            if (vis[newpos.first][newpos.second]) continue;
            bfs.push(newpos);
            dist[newpos.first][newpos.second] =
                dist[cur.first][cur.second] + 1;
            vis[newpos.first][newpos.second] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dist[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}


/*
g++ --std=c++17 A.cpp
*/

#include <iostream>
#include <iomanip> //! for setprecision(20)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

const int MOD = 1000000007;


int dist[50][50];
string s[50];



int main()
{
    const int INF = 1e9;
	cin.tie(0);
	ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    rep(i, h) cin >> s[i];
    int whiteCount = 0;
    rep(y, h) rep(x, w) {
        dist[y][x] = INF;
        if (s[y][x] == '.') ++whiteCount;
    }
    dist[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int y = q.front().first; int x = q.front().second; q.pop();
        int d = dist[y][x] + 1;
        rep(i, 4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && s[ny][nx] == '.' && d < dist[ny][nx]) {
                dist[ny][nx] = d;
                q.push({ny, nx});
            }
        }
    }

    int ans = -1;
    if (dist[h-1][w-1] != INF) {
        ans = whiteCount - dist[h-1][w-1];
    }
    cout << ans << endl;

    return 0;
}

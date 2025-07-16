#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <numeric>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))

int h, w;
vector< string > field;
vector< vector< bool > > reached;

using P = pair<s64, s64>;

P dfs(int y, int x, char c)
{
    P ret{0, 0};
    if (c == '#') ret.first = 1;
    else ret.second = 1;

    reached[y][x] = true;
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, -1, 0, 1};
    rep (i, 4)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (IN(0, h, ny) && IN(0, w, nx) && !reached[ny][nx] && field[ny][nx] != c)
        {
            P temp = dfs(ny, nx, field[ny][nx]);
            ret.first += temp.first;
            ret.second += temp.second;
        }
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    field.resize(h);
    reached.resize(h, vector<bool>(w, false));
    rep (i, h) cin >> field[i];

    s64 ans = 0;
    rep (i, h)
    {
        rep (j, w)
        {
            if (!reached[i][j] && field[i][j] == '#')
            {
                P p = dfs(i, j, '#');
                ans += p.first * p.second;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}


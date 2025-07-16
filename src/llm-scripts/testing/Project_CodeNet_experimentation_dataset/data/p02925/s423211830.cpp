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

vector< vs32 > g;
vs32 color;

const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

inline int enc(int i, int j)
{
    if (i < j) swap(i, j);
    return i * (i - 1) / 2 + j + 1;
}

int d[1000 * 1000];
int dfs(int u)
{
    if (color[u] == BLACK) return d[u];
    color[u] = GRAY;

    bool found = false;
    for (auto v : g[u])
    {
        if (color[v] == GRAY)
        {
            return -1;
        }
        int temp = dfs(v);
        if (temp == -1)
        {
            return -1;
        }
        found = true;
        d[u] = max(d[u], temp + 1);
    }
    color[u] = BLACK;
    return d[u];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int a;;
    color.resize(n * (n - 1) / 2 + 1, WHITE);
    g.resize(n * (n - 1) / 2 + 1);
    rep (i, n)
    {
        int u = 0;
        rep (j, n - 1)
        {
            cin >> a;
            --a;
            int v = enc(i, a);
            g[u].push_back(v);
            u = v;
        }
    }

    cout << dfs(0) << "\n";
    return 0;
}


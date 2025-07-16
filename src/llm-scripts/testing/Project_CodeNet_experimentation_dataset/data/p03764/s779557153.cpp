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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    s64 n, m;
    cin >> n >> m;
    vs64 x(n), y(m);
    rep (i, n)
    {
        cin >> x[i];
        if (x[i] < 0) x[i] += MOD;
    }
    rep (i, m)
    {
        cin >> y[i];
        if (y[i] < 0) y[i] += MOD;
    }

    s64 xadd, xsub, yadd, ysub;
    xadd = xsub = yadd = ysub = 0;
    rep (i, n)
    {
        xadd = (xadd + x[i] * i % MOD) % MOD;
        xsub = (xsub + x[n - i - 1] * i % MOD) % MOD;
    }
    xsub = MOD - xsub;
    rep (i, m)
    {
        yadd = (yadd + y[i] * i % MOD) % MOD;
        ysub = (ysub + y[m - i - 1] * i % MOD) % MOD;
    }
    ysub = MOD - ysub;

    cout << (((xadd + xsub) % MOD) * ((yadd + ysub) % MOD)) % MOD << "\n";
    return 0;
}


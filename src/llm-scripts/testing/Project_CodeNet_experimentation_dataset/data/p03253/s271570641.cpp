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

template< typename T >
map<T, int> prime_factorization(T x)
{
    map<T, int> ret;
    for (T i = 2; i * i <= x; ++i)
    {
        while (x % i == 0)
        {
            ++ret[i];
            x /= i;
        }
    }
    if (x != 1) ++ret[x];
    return ret;
}

s64 mypow(s64 x, s64 n)
{
    s64 ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret;
}

const int max_n = 100100;
s64 fac[max_n + 1];
s64 finv[max_n + 1];
void init(int n)
{
    fac[0] = fac[1] = 1;
    for (s64 i = 2; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    finv[n] = mypow(fac[n], MOD - 2);
    for (s64 i = n - 1; i >= 0; --i)
    {
        finv[i] = finv[i + 1] * (i + 1) % MOD;
    }
}

s64 comb(int n, int r)
{
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    auto pfac = prime_factorization(m);
    init(max_n);

    s64 ans = 1;
    for (auto& item : pfac)
    {
        int num = item.second;
        ans *= comb(n + num - 1, num);
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}


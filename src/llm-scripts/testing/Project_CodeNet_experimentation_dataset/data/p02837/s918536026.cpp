//{{{
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
#ifdef LOCAL
#include "prettyprint.hpp"
#endif
// clang-format off
void _print() { cerr << "]\033[0m\n"; }
template <typename T> void __print(T x) { cerr << x; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifdef LOCAL
#define debug(x...) cerr << "\033[1;34m[" << #x << "] = \033[1;32m["; _print(x)
#define debug_arr(x...) cerr << "\033[1;34m[" << #x << "] = \033[1;32m" << (x) << "\033[0m\n"
#else
#define debug(x...)
#define debug_arr(x...)
#endif
// clang-format on
//}}}

const int N = 20;
const int mod = 1e9 + 7;

int n;
int a[N];

vector<pii> words[N];

bool is_h(int status, int idx) { return (status & (1 << idx)) > 0; }
bool check(int status)
{
    for (int i = 0; i < n; i++)
    {
        // check ith person
        bool is_honest = is_h(status, i);
        if (is_honest == false) continue;

        for (int j = 0; j < a[i]; j++)
        {
            int p = words[i][j].first;
            int val = words[i][j].second;

            bool is_p_h = is_h(status, p);
            if (is_p_h != val) return false;
        }
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            words[i].clear();
            cin >> a[i];

            for (int j = 0; j < a[i]; ++j)
            {
                int x, y;
                cin >> x >> y;
                x--;
                words[i].push_back({x, y});
            }
        }

        int ans = -1;
        int lim = 1 << n;
        for (int st = 0; st < lim; st++)
        {
            // if (__builtin_popcount(st) <= ans) continue;

            // check
            if (check(st))
            {
                ans = max(ans, __builtin_popcount(st));
            }
        }

        // int v = __builtin_popcount(ans);
        cout << ans << endl;
    }

    return 0;
}

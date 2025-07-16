#include <bits/stdc++.h>

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif

//{{{
using namespace std;
typedef long long LL;
typedef vector<int> VI;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define clr(a, b) memset(a, b, sizeof(a))
// clang-format off
#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); cerr<<endl;}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while
(getline(ss, x, c)) v.push_back(x); return v;} void err(vector<string>::iterator) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args)
{cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}
// clang-format on
//}}}

int a[22][22];
int n;

LL dp[1 << 16];
LL val[1 << 16];

LL dfs(int st)
{
    if (dp[st] != -1) return dp[st];

    if (__builtin_popcount(st) == 1) return dp[st] = 0;

    LL ret = val[st];
    for (int i = st; i; i = (i - 1) & st)
    {
        if (i == st) continue;
        int st1 = i;
        int st2 = st ^ i;

        LL v = dfs(st1) + dfs(st2);
        if (v > ret) ret = v;
    }
    return dp[st] = ret;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        int lim = (1 << n) - 1;
        for (int st = 0; st <= lim; st++)
        {
            LL v = 0;
            for (int i = 0; i < n; i++)
            {
                if ((st & (1 << i)) == 0) continue;
                for (int j = i + 1; j < n; j++)
                {
                    if ((st & (1 << j)) == 0) continue;
                    v += a[i][j];
                }
            }
            val[st] = v;
        }

        clr(dp, -1);
        dp[0] = 0;
        LL ans = dfs(lim);
        cout << ans << endl;
    }

    return 0;
}

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

const int N = 2e5 + 10;
int T;

const int mod = 1e9 + 7;

int d;
char s[10010];
int dp[10010][111];
int len;

int dfs(int pos, int cursum, bool ding)
{
    if (pos == len)
    {
        return cursum == 0;
    }

    if (ding == false && dp[pos][cursum] != -1)
    {
        return dp[pos][cursum];
    }

    int ret = 0;

    int ed = 9;
    if (ding) ed = s[pos] - '0';
    for (int i = 0; i <= ed; i++)
    {
        int v = dfs(pos + 1, (cursum + i) % d, ding && i == ed);
        ret = (ret + v) % mod;
    }

    if (!ding) dp[pos][cursum] = ret;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
// freopen("out", "w", stdout);
#endif

    while (~scanf("%s", s))
    {
        scanf("%d", &d);
        len = strlen(s);

        clr(dp, -1);

        int ans = dfs(0, 0, true);
        ans = (ans - 1 + mod) % mod;
        printf("%d\n", ans);
    }

    return 0;
}

# include<bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

# define int long long

typedef long long ll;
typedef pair<int, int> pii;

# define S second
# define F first
# define kill(x) return(cout << x << '\n', 0LL)
# define debug(x) cerr<< #x << " = " << (x) << endl
# define ddebug(x, y) cerr<< #x << " = " << (x)  << ", " << #y << " = " << (y) << endl
# define tdebug(x, y, z) cerr<< #x << " = " << (x)  << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
# define bin(x) cerr<< #x << " : " << bitset<4>(x) << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define uop(x, y) pii(min(x, y), max(x, y))
# define MP(x, y) make_pair(x, y)

const int MAXN = 300 + 10;
int dp[MAXN][MAXN][MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;
	int k;
	cin >> s >> k;

	for (int t = 1; t <= sz(s); t ++)
	{
		for (int i = 0; i + t - 1 < sz(s); i ++)
		{
			int j = i + t - 1;
			for (int l = 0; l <= k; l ++)
			{
				if (t == 1)
				{
					dp[i][j][l] = 1;
					continue;
				}

				dp[i][j][l] = max(dp[i + 1][j][l], dp[i][j - 1][l]);
				if (l || s[i] == s[j])
					smax(dp[i][j][l], dp[i + 1][j - 1][l - (s[i] != s[j])] + 2);
			}
		}
	}
	cout << dp[0][sz(s) - 1][k] << '\n';

	return 0;
}

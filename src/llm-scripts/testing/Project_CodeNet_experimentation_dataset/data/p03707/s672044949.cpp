# include<bits/stdc++.h>

using namespace std;

# define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;

# define S second
# define F first
# define kill(x) return(cout << x << endl, 0)
# define debug(x) cerr<< #x << " : " << x << endl
# define ddebug(x, y) cerr<< #x << " : " << x  << ", " << #y << " : " << y << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)

const int MAXN = 2000 + 10;
int cnt[MAXN][MAXN], a1[MAXN][MAXN], a2[MAXN][MAXN];
string s[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i ++)
		cin >> s[i];

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + (s[i][j] - '0');


	for (int i = 0; i < n; i ++)
		for (int j = 1; j < m; j ++)
			a1[i + 1][j + 1] = a1[i + 1][j] + a1[i][j + 1] - a1[i][j] + (s[i][j] == '1' && s[i][j - 1] == '1');
	
	for (int i = 1; i < n; i ++)
		for (int j = 0; j < m; j ++)
			a2[i + 1][j + 1] = a2[i + 1][j] + a2[i][j + 1] - a2[i][j] + (s[i][j] == '1' && s[i - 1][j] == '1');

	while (q --)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (cnt[x2][y2] - (cnt[x2][y1 - 1] + cnt[x1 - 1][y2] - cnt[x1 - 1][y1 - 1])) - 
			((a1[x2][y2] - (a1[x2][y1] + a1[x1 - 1][y2] - a1[x1 - 1][y1])) +
			 (a2[x2][y2] - (a2[x1][y2] + a2[x2][y1 - 1] - a2[x1][y1 - 1]))) << endl;
	}

	return 0;
}





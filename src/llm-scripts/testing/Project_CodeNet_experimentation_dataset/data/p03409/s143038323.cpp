#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;

int used[110];

int main()
{
	int n;
	cin >> n;
	vector<pii> x(n), y(n);
	rep(i, n)
	{
		int a, b;
		cin >> a >> b;
		x[i] = make_pair(a, b);
	}
	rep(i, n)
	{
		int a, b;
		cin >> a >> b;
		y[i] = make_pair(a, b);
	}
	sort(all(x));
	sort(all(y));
	int ans = 0;
	rep(i, n)
	{
		int m = -1;
		int index = -1;
		rep(k, n)
		{
			if (used[k])
				continue;
			if (x[k].first < y[i].first && x[k].second < y[i].second && x[k].second > m)
			{
				m = x[k].second;
				index = k;
			}
		}
		if(index >= 0){
			used[index] = 1;
			ans++;
		}
		}
	cout << ans << endl;
}

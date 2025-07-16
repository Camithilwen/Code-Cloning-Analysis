#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

int n, m;
int p[1010];

int main()
{
	while (cin >> n >> m, n){
		rep(i, n) cin >> p[i];
		sort(p, p + n, greater<int>());
		int res = 0;
		rep(i, n) res += p[i];
		for (int i = m - 1; i < n; i += m){
			res -= p[i];
		}
		cout << res << endl;
	}
}
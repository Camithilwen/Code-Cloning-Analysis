#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
	alphanso;
	int n, k, i, gcd = 0, x, mx = INT_MIN;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		gcd = __gcd(gcd, x);
		mx = max(mx, x);
	}
	if (mx < k)
		cout << "IMPOSSIBLE";
	else
		!(k % gcd) ? cout << "POSSIBLE" : cout << "IMPOSSIBLE";
	return 0;
}
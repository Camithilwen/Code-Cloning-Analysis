#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int mod = 1e9 + 7;

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long ans = 0;
	long long all = 0;
	for (int i = 0; i < n; i++)
	{
		ans += all * a[i] % mod;
		ans %= mod;
		all += a[i];
		all %= mod;
	}
	cout << ans << endl;
	return (0);
}

#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n;
	cin >> n;
	
	vector<bool> seen(1'000'000'000);
	bool ans = true;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (seen[a])
			ans = false;
		seen[a] = true;
	}
	cout << (ans ? "YES" : "NO") << endl;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int h1, m1, h2, m2, k; cin >> h1 >> m1 >> h2 >> m2 >> k;
	int a = h1 * 60 + m1, b = h2 * 60 + m2;
	int ans = b - a;
	if (ans < 0) ans += 24 * 60;
	ans -= k;
	cout << ans << "\n";
	
	return 0;
}

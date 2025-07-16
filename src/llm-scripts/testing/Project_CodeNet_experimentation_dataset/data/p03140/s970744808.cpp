#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	string a, b, c; cin >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) {
			ans += 2;
		}
		else if ((a[i] == b[i] && b[i] != c[i]) || (b[i] == c[i] && c[i] != a[i]) || (c[i] == a[i] && a[i] != b[i])) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
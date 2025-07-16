#include <bits/stdc++.h>
using namespace std;
int main()
{
	// freopen("AGC010-D.in", "r", stdin);
	int n, cur = 0;
	cin >> n;
	vector<int> arr(n);
	copy(istream_iterator<int>(cin), istream_iterator<int>(), arr.begin());
	string str[] = {"First", "Second"}, ans;
	while (ans.empty()) {
		int cnt = count_if(arr.begin(), arr.end(), [&] (int x) { return x % 2 == 0; });
		if (cnt & 1) {
			ans = str[cur];
			break;
		}
		cur ^= 1;
		if (cnt != n - 1) {
			ans = str[cur];
		}
		int g = 0;
		for_each(arr.begin(), arr.end(), [&] (int x) {
			if (x == 1) {
				ans = str[cur];
			}
			x -= x & 1;
			while (x) {
				int r = g % x;
				g = x;
				x = r;
			}
		});
		if (!g) {
			break;
		}
		for_each(arr.begin(), arr.end(), [&] (int &x) { x /= g; });
	}
	cout << ans << endl;
	return 0;
}

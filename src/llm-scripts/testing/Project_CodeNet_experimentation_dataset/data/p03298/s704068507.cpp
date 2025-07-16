#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(a) cerr << #a << ": " << a << endl
 
typedef long long ll;
typedef pair<int, int> ii;
 
#define x first
#define y second
 
const int N = 20;

int n;
char s[2 * N];

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
 
	cin >> n;
	scanf("%s", s);

	vector< pair<string, string> > v1, v2;
	int mask_end = 1 << n;

	for (int mask = 0; mask < mask_end; mask++) {
		string tmp1, tmp2;
		for (int i = 0; i < n; i++) {
			if (mask & 1 << i) tmp1 += s[i];
			else tmp2 += s[i];
		}
		reverse(tmp2.begin(), tmp2.end());
		v1.push_back({tmp1, tmp2});
	}

	for (int mask = 0; mask < mask_end; mask++) {
		string tmp1, tmp2;
		for (int i = 0; i < n; i++) {
			if (mask & 1 << i) tmp1 += s[n + i];
			else tmp2 += s[n + i];
		}
		reverse(tmp2.begin(), tmp2.end());
		v2.push_back({tmp1, tmp2});
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	ll ans = 0LL;
	for (auto i : v1) {
		swap(i.x, i.y);
		auto res = equal_range(v2.begin(), v2.end(), i);
		ans += res.y - res.x;
	}

	cout << ans << endl;

	return 0;
}
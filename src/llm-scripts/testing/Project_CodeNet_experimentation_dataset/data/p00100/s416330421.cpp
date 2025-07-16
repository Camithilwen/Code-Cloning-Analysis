#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli employees[4001];
bool checked[4001];

signed main()
{
	lli n;
	while (cin >> n, n) {
		for (lli i = 1; i <= 4000; ++i) employees[i] = checked[i] = false;

		vector<lli> ans;

		for (lli i = 0; i < n; ++i) {
			lli num, a, b; cin >> num >> a >> b;

			if (checked[num]) continue;

			employees[num] += a * b;

			if (employees[num] >= 1000000) {
				ans.push_back(num);
				checked[num] = true;
			}
		}

		if (ans.size()) {
			for (lli i = 0; i < ans.size(); ++i) {
				cout << ans[i] << endl;
			}
		} else {
			cout << "NA" << endl;
		}
	}
}
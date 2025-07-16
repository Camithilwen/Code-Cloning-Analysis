#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(false);

	int n; cin >> n;

	vector<vector<int> > ten(20, vector<int>(20, 0));
	ll cnt = 0;
	REP(i, n) {
		double x; cin >> x;
		ll tmp = x * 1e9 + 0.1;
		int two = 0;
		int five = 0;
		while (!(tmp % 2)) {
			tmp /= 2;
			two++;
		}
		while (!(tmp % 5)) {
			tmp /= 5;
			five++;
		}
		if (two > 18) two = 18;
		if (five > 18) five = 18;
		for (int j = 18 - two; j <= 18; j++)
			for (int k = 18 - five; k <= 18; k++)
				cnt += ten[j][k];
		ten[two][five]++;
	}

	cout << cnt << '\n';
    return 0;
}

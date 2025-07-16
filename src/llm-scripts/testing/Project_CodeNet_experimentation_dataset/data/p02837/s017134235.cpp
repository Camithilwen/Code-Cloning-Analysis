#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll n;
vector<vector<P>>v;
bool check(int bit) {
	for (int i = 0; i < n; i++) {
		if (!(bit & (1 << i)))continue;

		for (P id : v[i]) {
			int x = id.first;
			int y = id.second;

			if (y == 1 && !(bit & (1 << x))) {
				return false;
			}

			if (y == 0 && (bit & (1 << x))) {
				return false;
			}
		}
	}
	return true;
}
int main(void) {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v[i].resize(a);
		for (int j = 0; j < a; j++) {
			cin >> v[i][j].first >> v[i][j].second;
			--v[i][j].first;
		}
	}

	int res = 0;
	for (int bit = 0; bit < (1 << n); bit++) {

		if (check(bit)) {
			int count = 0;
			for (int i = 0; i < n; i++) {
				if (bit & (1 << i)) {
					count++;
				}
			}
			res = max(res, count);
		}
	}
	cout << res << endl;
	return 0;
}
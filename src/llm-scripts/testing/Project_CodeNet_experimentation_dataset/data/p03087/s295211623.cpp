#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int>ac(n, 0), acsum(n + 1,0);
	for (int i = 0; i < n-1; i++) {
		if (s.substr(i, 2) == "AC") {
			ac[i]++;
			i++;
		}
	}
	rep(i, n)acsum[i + 1] = acsum[i] + ac[i];
	int l, r;
	rep(i, q) {
		cin >> l >> r;
		cout << acsum[r-1] - acsum[l-1] << endl;
	}
	return 0;
}


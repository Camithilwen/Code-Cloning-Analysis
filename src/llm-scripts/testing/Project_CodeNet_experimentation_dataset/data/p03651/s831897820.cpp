#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

	int n, k; cin >> n >> k;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	bool odd, even;
	odd = even = true;
	REP(i, n) {
		if (a[i] % 2) even = false;
		else odd = false;
	}
	bool allSame = true;
	bool diffFlag = true;
	int diff = INT_MAX;
	REP(i, n - 1) {
		if (abs(a[i] - a[i+1]))
			diff = min(diff, abs(a[i] - a[i+1]));
	}
	REP(i, n - 1) {
		if (a[i] != a[i+1])
			allSame = false;
		if (abs(a[i] - a[i+1]) % diff)
			diffFlag = false;
	}

	if (k > *max_element(a.begin(), a.end())) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else if (find(a.begin(), a.end(), k) != a.end()) {
		cout << "POSSIBLE" << '\n';
	}
	else if (allSame) {
		cout << ((k == a[0]) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
	}
	else if (diffFlag) {
		cout << ((k % diff == 0) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
	}
	else {
		if (k % 2) {
			bool ok = true;
			if (even) ok = false;
			if (k == 1 && (even || odd)) ok = false;
			cout << ((ok) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
		}
		else {
			cout << "POSSIBLE" << '\n';
		}
	}
    return 0;
}

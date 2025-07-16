#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<tuple<int, int, int>>stx(N);
	for (int n = 0;n<N;++n) {
		cin >> get<1>(stx[n]) >> get<2>(stx[n]) >> get<0>(stx[n]);
	}
	sort(stx.begin(), stx.end());

	set<pair<int, int>> d;
	for (int i = 0, x; i < Q; ++i) {
		cin >> x;
		d.emplace(x, i);
	}

	vector<long long>tm(Q, -1);
	for (int i = 0;i<N;++i) {
		auto first = d.lower_bound(make_pair(get<1>(stx[i]) - get<0>(stx[i]), 0));
		auto end = d.upper_bound(make_pair(get<2>(stx[i]) - get<0>(stx[i]) - 1, Q));

		for (auto it = first; it != end; ++it) {
			tm[it->second] = get<0>(stx[i]);
		}
		d.erase(first, end);
	}
	for (int i = 0; i < Q; ++i) cout << tm[i] << '\n';
	return 0;
}
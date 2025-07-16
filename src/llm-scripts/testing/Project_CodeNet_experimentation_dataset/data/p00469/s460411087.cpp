#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, k; 
	while (cin >> n >> k, n + k) {
		vector<int> card(n);
		for (int i = 0; i < n; ++i) cin >> card[i];
		sort(card.begin(), card.end());
		set<int> cnt;
		do {
			int tmp = 0;
			for (int i = 0; i < k; ++i)
				tmp = tmp * (card[i] >= 10 ? 100 : 10) + card[i];
			cnt.insert(tmp);
		} while (next_permutation(card.begin(), card.end()));
		cout << cnt.size() << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

typedef long long ll;

using std::cin;
using std::cout;

const int MaxN = 100005;

int n, m; ll k;
int buk[MaxN];
ll arr[MaxN], tmp[MaxN];
bool vis[MaxN];

int main() {
	cin >> n;
	std::copy_n(std::istream_iterator<int>(cin), n, arr);
	cin >> m >> k;
	std::iota(buk, buk + n, 0);
	while (m--) {
		int pos; cin >> pos;
		std::swap(buk[pos - 1], buk[pos]);
	}
	std::adjacent_difference(arr, arr + n, tmp);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			std::vector<int> vec;
			int j = i;
			do {
				vis[j] = true;
				vec.push_back(j);
				j = buk[j];
			} while (j != i);
			int len = vec.size();
			for (int p = 0; p < len; ++p) {
				int from = vec[p];
				int to = vec[(p + k) % len];
				arr[from] = tmp[to];
			}
		}
	}
	std::partial_sum(arr, arr + n, std::ostream_iterator<ll>(cout, "\n"));
	return 0;
}
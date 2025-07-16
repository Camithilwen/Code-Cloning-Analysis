#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

class BIT {
	std::vector<LL> bit;
	LL size;
public:
	BIT() { }
	BIT(LL sz) { init(sz); }
	void init(LL sz) {
		bit = std::vector<LL>((size = sz) + 1);
	}
	LL sum(LL i) {
		LL s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
}
	void add(LL i, LL x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int main() {
	LL N, Q, a, t, x, y;
	cin >> N >> Q;
	BIT bit(N);
	for (LL i = 1; i <= N; ++i) {
		cin >> a;
		bit.add(i, a);
	}
	for (LL i = 0; i < Q; ++i) {
		cin >> t >> x >> y;
		if (t == 0) {
			bit.add(x + 1, y);
		} else {
			cout << (bit.sum(y) - bit.sum(x)) << endl;
		}
	}
	return 0;
}

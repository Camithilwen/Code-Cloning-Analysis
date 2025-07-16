#define FILEIO(a) freopen(a".in", "r", stdin); freopen(a".out", "w", stdout);
#include <cstdio>
#include <algorithm>
#include <numeric>

typedef long long ll;

const int MaxN = 100005;

inline int div_ceil(ll a, int b) {
	return (a + b - 1) / b;
}

int n, W;
struct node {
	int b, l, r; ll val;
	
	node() = default;
	node(int b, int l, int r): b(b), l(l), r(r) {
		val = (ll)r * (W - b) + (ll)l * b;
	}
	
	inline int calc(ll s) const {
		if (s >= val) return W;
		ll tmp = s - (ll)b * l;
		return tmp > 0 ? b + div_ceil(tmp, r) : div_ceil(s, l);
	}
} dat[MaxN];

ll solve() {
	scanf("%d%d", &n, &W);
	
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int b, l, r;
		scanf("%d%d%d", &b, &l, &r);
		dat[i] = node(b, l, r);
		sum -= (ll)l * b;
	}
	
	std::sort(dat, dat + n, [](const node &a, const node &b) {
		return a.val > b.val;
	});
	
	for (int i = 0; i < n; ++i) {
		ll val = dat[i].val;
		if (sum + val >= 0) {
			int res = W;
			for (int j = 0; j < i; ++j) {
				res = std::min(res, dat[j].calc(-sum + dat[j].val - val));
			}
			for (int j = i; j < n; ++j) {
				res = std::min(res, dat[j].calc(-sum));
			}
			return (ll)i * W + res;
		}
		sum += val;
	}
	
	return (ll)n * W;
}

int main() {
	printf("%lld\n", solve());
	return 0;
}
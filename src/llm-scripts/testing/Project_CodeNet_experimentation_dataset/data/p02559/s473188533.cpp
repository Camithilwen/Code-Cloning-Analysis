#include <atcoder/scc>;
#include <atcoder/convolution>
#include <atcoder/modint>
#include <atcoder/math>
#include <atcoder/fenwicktree>
#include <atcoder/dsu>
#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}
ll mod = 998244353;
int main() {
	ll N, Q;
	cin >> N >> Q;
	vector<ll> t(Q);
	vector<ll> u(Q);
	vector<ll> v(Q);
	fenwick_tree<long long> fw(N);
	rep(i, N) {
		ll a;
		cin >> a;
		fw.add(i, a);
	}
	rep(i,Q) {
		cin >> t.at(i) >> u[i] >> v[i];

	}

	rep(i, Q) {
		if (t[i] == 0) {
			fw.add(u[i], v[i]);
		}
		else {
			cout << fw.sum(u[i], v[i]) << endl;;
		}
	}
}
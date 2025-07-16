#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T>inline bool chmax(T &a, T b){return (a < b ? a = b, true : false);}
template<typename T>inline bool chmin(T &a, T b){return (a > b ? a = b, true : false);}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;
const long double EPS = 1e-9;



template<typename T>
class RangeUpdateQuery {
private:
	vector<T> data, lazy;
	vector<bool> valid, lazyFlag;
	int sz;
	void push(int k) {
		if (this->lazyFlag[k]) {
			this->valid[k] = true;
			this->data[k] = this->lazy[k];
			if (k * 2 + 2 < sz * 2 - 1) {
				this->lazy[k * 2 + 1] = this->lazy[k * 2 + 2] = this->lazy[k];
				this->lazyFlag[k * 2 + 1] = this->lazyFlag[k * 2 + 2] = true;
			}
			this->lazyFlag[k] = false;
		}
	}
	void update(int l, int r, int L, int R, int k, T val) {
		this->push(k);
		if (L <= l && r <= R) {
			this->lazy[k] = val;
			this->lazyFlag[k] = true;
			this->push(k);
		} else if (r < L || R < l) {
			return;
		} else if (r - l > 1) {
			const int mid = (l + r) / 2;
			this->update(l, mid, L, R, k * 2 + 1, val);
			this->update(mid, r, L, R, k * 2 + 2, val);
		}
	}
	T query(int l, int r, int idx, int k) {
		this->push(k);
		if (r - l == 1) {
			if (!valid[k]) {
				throw exception();
			}
			return this->data[k];
		} else if (l <= idx && idx <= r) {
			const int mid = (l + r) / 2;
			if (idx < mid) {
				return this->query(l, mid, idx, k * 2 + 1);
			} else {
				return this->query(mid, r, idx, k * 2 + 2);
			}
		}
	}
public:
	RangeUpdateQuery(const int n) {
		this->sz = 1;
		while (this->sz < n) this->sz <<= 1;
		this->data.resize(this->sz * 2 - 1);
		this->lazy.resize(this->sz * 2 - 1);
		this->valid.resize(this->sz * 2 - 1, false);
		this->lazyFlag.resize(this->sz * 2 - 1, false);
	}
	void update(int l, int r, T val) {
		this->update(0, sz, l, r, 0, val);
	}
	T query(int idx) {
		return this->query(0, sz, idx, 0);
	}
};

int main() {
	int n, q;
	cin >> n >> q;
	RangeUpdateQuery<int> ruq(n);
	while (q--) {
		int num; cin >> num;
		if (num) {
			int idx; cin >> idx;
			try {
				cout << ruq.query(idx) << endl;
			} catch (exception e) {
				cout << (1ll << 31) - 1 << endl;
			}
		} else {
			int s, t, x;
			cin >> s >> t >> x;
			ruq.update(s, t + 1, x);
		}
	}
}
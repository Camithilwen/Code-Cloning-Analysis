#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define repi(i, x) \
	for (auto i = (x).begin(), i##_fin = (x).end(); i != i##_fin; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a) ? "Yes" : "No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int, int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long, long long> P;
typedef vector<P> VP;
template <class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 30;
const double PI       = acos(-1);
int main() {
	int n;
	int ans = 0;
	cin >> n;
	int v;
	pair<Pi, Pi> as = mp(mp(0, 0), mp(0, 0));
	pair<Pi, Pi> bs = mp(mp(0, 0), mp(0, 0));
	pair<map<int, int>, map<int, int>> dis;
	rep(i, n) {
		cin >> v;
		if (i % 2) {
			dis.F[v]++;
		} else {
			dis.S[v]++;
		}
	}
	repi(itr, dis.F) {
		if (itr->S > as.F.S) {
			as.S = as.F;
			as.F = *itr;
		} else if (itr->S > as.S.S) {
			as.S = *itr;
		}
	}
	repi(itr, dis.S) {
		if (itr->S > bs.F.S) {
			bs.S = bs.F;
			bs.F = *itr;
		} else if (itr->S > bs.S.S) {
			bs.S = *itr;
		}
	}
	if (as.F.F != bs.F.F) {
		ans = n - as.F.S - bs.F.S;
	} else {
		ans = n - max(as.F.S + bs.S.S, as.S.S + bs.F.S);
	}

	cout << ans << endl;
}
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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
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
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	rep(i, v.size()) {
		if (i) os << ",";
		os << v[i];
	}
	os << "}";
	return os;
}
template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
	rep(i, v.size()) { is >> v[i]; }
	return is;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 30;
const double PI       = acos(-1);

int main() {
	int n;
	string s;
	ll ans = 0LL;
	cin >> n >> s;
	vector<string> dis1, dis2;
	string bef = "";
	for (int bit = 0; bit < (1 << n); bit++) {
		bef = "";
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				bef += s[i];
			}
		}
		bef += '0';
		for (int i = n - 1; i >= 0; i--) {
			if ((bit & (1 << i)) == 0) {
				bef += s[i];
			}
		}
		dis1.pb(bef);
		// clog << bef << endl;
		bef = "";
		//--------//

		for (int i = n - 1; i >= 0; i--) {
			if ((bit & (1 << i)) == 0) {
				bef += s[i + n];
			}
		}
		bef += '0';
		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				bef += s[i + n];
			}
		}

		dis2.pb(bef);
		//	clog << bef << endl;
	}
	sort(all(dis1));
	sort(all(dis2));
	repi(i,dis1){
		ans +=
		    distance(lower_bound(all(dis2), *i), upper_bound(all(dis2), *i) );
	//	clog << ans << endl;
	}
	cout << ans << endl;
}
/*
半分全挙列
chose red; head last: blue
chose bule: head last: red

top!= head: rr- bb- -> 2n:: n
2^n * log(n^2)


cabaacba = caba \ acba
c  -> /  aba ->
aba   <-/ <- c
== c aba   /  c aba
ab  ->/ ac
ca <-/ ba
== ab ac / ab ac
*/
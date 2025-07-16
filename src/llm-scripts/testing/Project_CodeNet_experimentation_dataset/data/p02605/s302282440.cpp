#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
	int N;
	cin >> N;
	
	vector<int> X(N), Y(N);
	vector<char> U(N);
	
	map<char, int> conv;
	char conv_table[5] = "URDL";
	REP(i, 4) conv[conv_table[i]] = i;
	
	REP(i, N) {
		char c;
		scanf("%d %d %c", &X[i], &Y[i], &c);
		U[i] = c;
	}
	
	map<int, vector<pii>> lr, ud, ru, rd;
	REP(i, N) {
		lr[Y[i]].emplace_back(X[i], U[i]);
		ud[X[i]].emplace_back(Y[i], U[i]);
		ru[X[i] - Y[i]].emplace_back(X[i], U[i]);
		rd[X[i] + Y[i]].emplace_back(X[i], U[i]);
	}
	
	int ans = INF;
	for (auto &it : lr) {
		vector<pii> v = it.se;
		vector<int> ord(v.size());
		iota(ALL(ord), 0);
		sort(ALL(ord), [&](int i, int j) {
			return v[i].fi < v[j].fi;
		});
		int last = -INF;
		for (int i : ord) {
			if (v[i].se == 'R') last = v[i].fi;
			else if (v[i].se == 'L' && last != -INF) chmin(ans, (v[i].fi - last) * 5);
		}
	}
	for (auto &it : ud) {
		vector<pii> v = it.se;
		vector<int> ord(v.size());
		iota(ALL(ord), 0);
		sort(ALL(ord), [&](int i, int j) {
			return v[i].fi < v[j].fi;
		});
		int last = -INF;
		for (int i : ord) {
			if (v[i].se == 'U') last = v[i].fi;
			else if (v[i].se == 'D' && last != -INF) chmin(ans, (v[i].fi - last) * 5);
		}
	}
	for (auto &it : ru) {
		vector<pii> v = it.se;
		vector<int> ord(v.size());
		iota(ALL(ord), 0);
		sort(ALL(ord), [&](int i, int j) {
			return v[i].fi < v[j].fi;
		});
		int lastu = -INF, lastr = -INF;
		for (int i : ord) {
			if (v[i].se == 'U') lastu = v[i].fi;
			else if (v[i].se == 'R') lastr = v[i].fi;
			else if (v[i].se == 'D' && lastr != -INF) chmin(ans, (v[i].fi - lastr) * 10);
			else if (v[i].se == 'L' && lastu != -INF) chmin(ans, (v[i].fi - lastu) * 10);
		}
	}
	for (auto &it : rd) {
		vector<pii> v = it.se;
		vector<int> ord(v.size());
		iota(ALL(ord), 0);
		sort(ALL(ord), [&](int i, int j) {
			return v[i].fi < v[j].fi;
		});
		int lastr = -INF, lastd = -INF;
		for (int i : ord) {
			if (v[i].se == 'R') lastr = v[i].fi;
			else if (v[i].se == 'D') lastd = v[i].fi;
			else if (v[i].se == 'U' && lastr != -INF) chmin(ans, (v[i].fi - lastr) * 10);
			else if (v[i].se == 'L' && lastd != -INF) chmin(ans, (v[i].fi - lastd) * 10);
		}
	}
	
	if (ans == INF) puts("SAFE");
	else cout << ans << endl;
	return 0;
}

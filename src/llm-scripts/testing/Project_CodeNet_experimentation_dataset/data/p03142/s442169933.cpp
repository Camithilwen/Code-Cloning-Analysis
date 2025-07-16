#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

struct edge {
	ll to;
	ll cost;
};

//トポソ
void toposo_(vector<vector<edge>>& g, vector<int>& used, vector<int>& l, int pos) {
	if (!used[pos]) {
		used[pos] = 1;
		for (int i = 0; i < g[pos].size(); i++) {
			toposo_(g, used, l, g[pos][i].to);
		}
		l.push_back(pos);
	}
}
vector<int> toposo(vector<vector<edge>>& g) {
	vector<int> u(g.size(), 0), ret;
	for (int i = 0; i < g.size(); i++)toposo_(g, u, ret, i);
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<edge>> g(N);
	vector<vector<int>> pars(N);
	for (int i = 0; i < N + M - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back({ v,1 });
		pars[v].push_back(u);
	}

	vector<int> a = toposo(g);
	vector<int> used(N, 0), ans(N);
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			ans[a[i]] = -1;
			used[a[i]] = i+1;
		}
		else {
			ll t1, t2 = -1;
			for (int j = 0; j < pars[a[i]].size(); j++) {
				if (used[pars[a[i]][j]] != 0) {
					if (t2 < used[pars[a[i]][j]]) {
						t1 = pars[a[i]][j];
						t2 = used[pars[a[i]][j]];
					}
				}
			}
			ans[a[i]] = t1;
			used[a[i]] = i + 1;
		}
		//cout << a[i] << endl;
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] + 1 << endl;
	}
}
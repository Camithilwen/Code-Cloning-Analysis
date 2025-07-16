#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stdio.h>
#include <functional>
#include <chrono>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
constexpr ll MAX_INF = 9223372036854775807;
constexpr ll MOD = (1e9 + 7);
//constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

template<class T>
vector<vector<T>> vvt(T init, ll m, ll n) {
	vector<vector<T>> ans = vector<vector<T>>(m, vector<T>(n, init));
	return move(ans);
}

template<class T>
vector<T> vt(T init, ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T>& v) {
	T ans = -INF;
	rep(i, 0, v.size()) {
		ans = max(ans, v[i]);
	}
	return ans;
}

// 素数判定
bool judge(ll n) {
	for (ll i = 2; i * i <= n; i++) if (n %= i)return false;
	return true;
}


template <class C>
void print(const C & c, std::ostream & os = std::cout)
{
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, ", "));
	os << std::endl;
}
/*
ll count(ll n,ll r) {
	ll ans = 0,check = 1;
	rep(i,0, r) {
		if ((n & check) > 0) {
			ans++;
		}
		check = check << 1;
	}
	return ans;
}
*/
bool sortreverse(ll a, ll b) {
	return a > b;
}

ll kiriage(ll a, ll b) {
	if (a % b == 0)return a / b;
	return a / b + 1;
}

ll n, m, x, y, t, q, s,k,h,w;

bool topologicalSort(vector<vector<long long>>& graph, vector<long long>& ans) {
	vector<unordered_set<long long>> inGraph(graph.size());
	vector<long long> node,check(graph.size(),0);
	rep(i, 0, graph.size()) {
		rep(j, 0, graph.at(i).size()) {
			inGraph.at(graph.at(i).at(j)).insert(i);
		}
	}
	rep(i, 0, graph.size()) {
		if (inGraph.at(i).size() == 0)node.push_back(i);
	}
	while (! node.empty()) {
		long long v = node.back();
		node.pop_back();
		ans.push_back(v);
		rep(i, 0, graph.at(v).size()) {
			inGraph.at(graph.at(v).at(i)).erase(v);
			if (inGraph.at(graph.at(v).at(i)).size() == 0) {
				node.push_back(graph.at(v).at(i));
			}
		}
		check.at(v) = 1;
	}
	for (long long v : check) {
		if (v == 0)return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	vvl graph(n);
	rep(i, 0, n + m - 1) {
		cin >> x >> y;
		graph.at(x - 1).push_back(y - 1);
	}
	vl result;
	topologicalSort(graph, result);
	vl num(n);
	rep(i, 0, n) {
		num[result[i]] = i;
	}

	vvl in(n);
	rep(i, 0, n) {
		for (ll v : graph[i]) {
			in[v].push_back(i);
		}
	}

	rep(i, 0, n) {
		ll oya = -1, c = -1;
		rep(j, 0, in[i].size()) {
			if (c < num[in[i][j]]) {
				oya = in[i][j];
				c = num[in[i][j]];
			}
		}
		printf("%lld\n", oya + 1);
	}
}
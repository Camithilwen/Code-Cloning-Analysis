//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

vector<vector<ll>> graph;
vector<bool> visited;

void dfs(ll now) {
	visited[now] = true;
	for (ll to : graph[now]) {
		if (!visited[to]) {
			dfs(to);
		}
	}
}

int main() {
	ll N, M;
	cin >> N >> M;
	graph.resize(2*N);
	rep(i,0,M) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[2*a].push_back(2*b+1);
		graph[2*b+1].push_back(2*a);
		graph[2*a+1].push_back(2*b);
		graph[2*b].push_back(2*a+1);
	}
	visited.resize(2*N);
	dfs(0);
	ll cnt = 0;
	rep(i,0,N) {
		if (visited[2*i]) {
			cnt++;
		}
	}
	ll ans = 0;
	rep(i,0,N) {
		bool have_true = false;
		bool have_false = false;
		for (ll to : graph[2*i]) {
			to /= 2;
			if (visited[2*to]) {
				have_true = true;
			} else {
				have_false = true;
			}
		}
		ll ans_loc = 0;
		if (have_true) {
			ans_loc += cnt;
			if (visited[2*i]) {
				ans_loc--;
			}
		}
		if (have_false) {
			ans_loc += N - cnt;
			if (!visited[2*i]) {
				ans_loc--;
			}
		}
		// cout << i+1 << ":" << ans_loc << endl;
		ans += ans_loc;
	}
	cout << ans / 2 - M << endl;
}

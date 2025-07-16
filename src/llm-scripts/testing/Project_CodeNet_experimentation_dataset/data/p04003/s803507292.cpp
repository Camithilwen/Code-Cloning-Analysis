#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
#include <omp.h>
using namespace std;
#define eps 0.000001
#define LONG_INF 100000000000000
#define GOLD 1.61803398874989484820458
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
vector<vector<pair<int, int>>> vertexs;
vector<pair<int, int>> unioning[1000001];
pair<int, int> union_tree[10000001];
int union_find(int now) {
	if (union_tree[now].first == now) return now;
	return union_tree[now].first = union_find(union_tree[now].first);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	union_tree[b].second += union_tree[a].second;
	union_tree[a].first = union_tree[b].first;
	union_tree[a].second = 0;
	return 0;
}
vector<int> ans, visited;
int main() {
	int n, m;
	cin >> n >> m;
	int base = n - 1;
	REP(i, n) {
		vertexs.push_back(vector<pair<int, int>>());
	}
	set<int> listings;
	REP(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		listings.insert(c);
		unioning[c].push_back(make_pair(a, b));
	}
	REP(i, n) {
		union_tree[i] = make_pair(i, 1);
	}
	for (auto tea = listings.begin(); tea != listings.end(); ++tea) {
		int i = *tea;
		set<int> as;
		for (int q = 0; q < unioning[i].size(); ++q) {
			int a = unioning[i][q].first;
			int b = unioning[i][q].second;
			union_merge(a, b);
			as.insert(a);
			as.insert(b);
		}
		map<int, int> gogo;
		for (auto q = as.begin(); q != as.end(); ++q) {
			int topping = union_find(*q);
			if (gogo[topping] == 0) {
				gogo[topping] = vertexs.size();
				vertexs.push_back(vector<pair<int, int>>());
			}
			vertexs[*q].push_back(make_pair(gogo[topping], 1));
			vertexs[gogo[topping]].push_back(make_pair(*q, 0));
		}
		for (auto q = as.begin(); q != as.end(); ++q) {
			union_tree[*q] = make_pair(*q, 1);
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next;
	next.push(make_pair(0, 0));
	ans.push_back(0);
	visited.push_back(0);
	for (int i = 1; i < vertexs.size(); ++i) {
		ans.push_back(10000000);
		visited.push_back(0);
	}
	while (next.empty() == false) {
		int now = next.top().second;
		next.pop();
		if (visited[now] == true) continue;
		visited[now] = true;
		for (int i = 0; i < vertexs[now].size(); ++i) {
			if (ans[vertexs[now][i].first] > ans[now] + vertexs[now][i].second) {
				ans[vertexs[now][i].first] = ans[now] + vertexs[now][i].second;
				next.push(make_pair(ans[vertexs[now][i].first], vertexs[now][i].first));
			}
		}
	}
	if (ans[base] == 10000000) {
		cout << -1 << endl;
	}
	else {
		cout << ans[base] << endl;
	}
	return 0;
}

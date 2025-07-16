#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

namespace SCC {
	const vector<vector<size_t>> *map, *revMap;
	vector<size_t> parent, topological;
	vector<bool> visit;
	size_t n, current;

	size_t find(size_t p) {
		size_t &q = parent[p];
		if (p == q) return p;
		return q = find(q);
	}

	inline void merge(size_t p, size_t q) {
		p = find(p);
		q = find(q);
		parent[q] = p;
	}

	inline void init(const size_t len) {
		parent.resize(len);
		for (size_t i = 0; i < len; i++) parent[i] = i;
	}

	void topologicalSort(size_t idx) {
		if (visit[idx]) return;
		visit[idx] = true;

		for (auto v : map->at(idx)) topologicalSort(v);

		topological.emplace_back(idx);
	}

	void getSCC(size_t idx) {
		if (visit[idx]) return;
		visit[idx] = true;

		for (auto v : revMap->at(idx)) getSCC(v);
		merge(current, idx);
	}

	vector<size_t>& SCC(const vector<vector<size_t>> &m, const vector<vector<size_t>> &revM) {
		map = &m;
		revMap = &revM;
		n = m.size();
		init(n);

		topological.clear();
		visit.resize(n);

		fill(visit.begin(), visit.end(), false);
		for (size_t i = 0; i < n; i++) topologicalSort(i);

		fill(visit.begin(), visit.end(), false);
		for (auto i = topological.rbegin(); i != topological.rend(); i++) {
			current = *i;
			getSCC(*i);
		}
		for (size_t i = 0; i < n; i++) find(i);

		return parent;
	}
}

int main() {
	vector<vector<size_t>> inM, outM;
	size_t n, m, a, b;
	scanf("%zd%zd", &n, &m);
	inM.resize(n);
	outM.resize(n);

	while (m--) {
		scanf("%zd%zd", &a, &b);
		inM[b].emplace_back(a);
		outM[a].emplace_back(b);
	}

	SCC::SCC(inM, outM);
	scanf("%zd", &m);
	while (m--) {
		scanf("%zd%zd", &a, &b);
		puts(SCC::parent[a] == SCC::parent[b] ? "1" : "0");
	}

	/*
	map<size_t, vector<size_t>> s;
	SCC::SCC(inM, outM);
	for (size_t i = 0; i < n; i++) {
		s[SCC::parent[i]].emplace_back(i);
	}
	printf("%zd\n", s.size());
	for (auto &v : s) {
		for (auto t : v.second) printf("%zd ", ++t);
		puts("-1");
	}
	*/
}
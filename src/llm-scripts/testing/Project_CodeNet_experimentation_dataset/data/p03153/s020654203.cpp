#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define LL long long
#define LP pair<LL, LL>
const LL inf = 1e17;
struct segtree {
	int n = 1;
	vector<LP> node;//cost, place
	void init(int N) {
		node.clear();
		while (N > n) n *= 2;
		node.resize(n * 2, { inf, inf });
	}

	void update(int k, LL x, int a) {

		k += n - 1;
		node[k] = { x, a };
		while (k > 0) {
			k = (k - 1) / 2;
			int l = k * 2 + 1;
			int r = k * 2 + 2;
			if (node[l].first < node[r].first) node[k] = node[l];
			else node[k] = node[r];
		}
	}

	LP mini(int a, int b, int k = 0, int l = 0, int r = -1) {

		if (r < 0) r = n;
		if (b <= l || r <= a) return { inf, inf };
		if (a <= l && r <= b) return node[k];
		LP ln = mini(a, b, k * 2 + 1, l, (l + r) / 2);
		LP rn = mini(a, b, k * 2 + 2, (l + r) / 2, r);
		if (ln.first < rn.first) return ln;
		else return rn;
	}
};

struct edge {
	LL to;
	LL cost;
	bool operator<(const edge &e1) const {
		return e1.cost < cost;
	}
};

int N;
int idx[200010];
LL D;
bool used[200010];
vector<LL> A;
vector<LP> B;
vector<edge> G[200010];

LL prim() {
	priority_queue<edge> pq;
	pq.push(edge{ 0, 0 });
	LL total = 0;
	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		if (!used[e.to]) {
			used[e.to] = true;
			total += e.cost;
			for (auto u : G[e.to]) {
				if (!used[u.to]) pq.push(u);
			}
		}
	}
	return total;
}

void build() {
	segtree seg;
	seg.init(N);

	for (int i = 0; i < N; i++) {
		seg.update(idx[i], A[i] + D * (N - i - 1), idx[i]);
		if (i != 0) {
			LP lp = seg.mini(0, idx[i]);
			if (lp.first == inf) continue;

			lp.first -= D * (N - i - 1) - A[i];
			G[B[lp.second].second].push_back(edge{ i, lp.first });
			G[i].push_back(edge{ B[lp.second].second, lp.first });
		}
	}

	seg.init(N);
	for (int i = N - 1; i >= 0; i--) {
		seg.update(idx[i], A[i] + D * i, idx[i]);
		if (i != N - 1) {
			LP lp = seg.mini(0, idx[i]);
			if (lp.first == inf) continue;

			lp.first -= D * i - A[i];
			G[B[lp.second].second].push_back(edge{ i, lp.first });
			G[i].push_back(edge{ B[lp.second].second, lp.first });
		}
	}
}

void init() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		LP tmp;
		cin >> tmp.first;
		tmp.second = i;
		A.push_back(tmp.first);
		B.push_back(tmp);
	}
	sort(B.begin(), B.end());

	for (int i = 0; i < N; i++) {
		idx[B[i].second] = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	build();
	cout << prim() << endl;
	return 0;
}
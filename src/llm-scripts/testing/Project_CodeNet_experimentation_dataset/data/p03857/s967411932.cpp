#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
#define db double long
const int siz = 2 * 1e5 + 7;
int parent1[siz];
int nodesize1[siz];
int parent2[siz];
int nodesize2[siz];
int get2(int x) {
	if (parent2[x] == x)return x;
	return parent2[x] = get2(parent2[x]);
}
void dsu2(int u, int v) {
	u = get2(u);
	v = get2(v);
	if (v != u) {
		if (rand() & 1)swap(u, v);
		parent2[v] = u;
		nodesize2[u] += nodesize2[v];
		nodesize2[v] = 0;
	}
}
int get1(int x) {
	if (parent1[x] == x)return x;
	return parent1[x] = get1(parent1[x]);
}
void dsu1(int u, int v) {
	u = get1(u);
	v = get1(v);
	if (v != u) {
		if (rand() & 1)swap(u, v);
		parent1[v] = u;
		nodesize1[u] += nodesize1[v];
		nodesize1[v] = 0;
	}
}
void clear() {
	for (int i = 0; i < siz; i++) {
		parent1[i] = i;
		nodesize1[i] = 1;
		parent2[i] = i;
		nodesize2[i] = 1;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, l;
	cin >> n >> k >> l;
	clear();
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (get1(a) != get1(b)) {
			dsu1(a, b);
		}
	}
	for (int i = 0; i < l; i++) {
		int a, b;
		cin >> a >> b;
		if (get2(a) != get2(b)) {
			dsu2(a, b);
		}
	}
	map<pi, int>m;
	for (int i = 1; i <= n; i++) {
		m[mk(get1(i), get2(i))]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << m[mk(get1(i), get2(i))] << " ";
	}
	cout << endl;
}

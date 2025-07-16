#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

struct Value {
	int depth, cost;
	Value() { }
	Value(int depth, int cost) {
		this->depth = depth;
		this->cost = cost;
	}
};

int n, k;
int a[100000];
vector<int> et[100000];

Value dfs(int p, int v) {
	Value ret(0, 0);
	
	for (int i = 0; i < et[v].size(); i++) {
		int nv = et[v][i];
		if (nv == p) continue;
		Value res = dfs(v, nv);
		ret.depth = max(ret.depth, res.depth + 1);
		ret.cost += res.cost;
	}
	
	if (ret.depth == k - 1 && p != 0) {
		ret.depth = -1;
		ret.cost++;
	}
	return ret;
}

int main() {
	int i;
	
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i]; a[i]--;
		if (i != 0) {
			et[a[i]].push_back(i);
		}
	}
	
	int ans = dfs(0, 0).cost;
	if (a[0] != 0) ans++;
	cout << ans << endl;
	return 0;
}
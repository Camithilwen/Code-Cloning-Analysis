#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
int a[100000];
vector<int> G[100000];
int in[100000];
int N, K;
int ans;
int solve(int v) {
	if (G[v].size() == 0) return 0;
	int ma = 0;
	for (int to : G[v]) {
		int t = solve(to) + 1;
		if (t == K && v > 0) {
			t = 0;
			ans++;
		}
		ma = max(ma, t);
	}
	return ma;

}
int main() {
	cin >> N >> K;
	rep(i, N) {
		cin >> a[i];
		a[i]--;
	}
	if (a[0] != 0) ans++;
	for (int i = 1; i < N; i++) {
		G[a[i]].push_back(i);
	}
	solve(0);
	cout << ans << endl;
}

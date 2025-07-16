#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long long  i=a;i<n;i++)
#define sz(A) (int)(A.size())
#define all(x) (x).begin(),(x).end()
#define get(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
void solve() {
	int n;
	cin >> n;
	map<int,set<int> > L, R, U, D;
	map<int, set<int> > L2, R2, U2, D2;
	map<int, set<int> > L3, R3, U3, D3;
	rep(i, 0, n) {
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		if (dir == 'U') {
			U[x].insert(y);
			U2[x + y].insert(y);
			U3[x - y].insert(y);
		}
		if (dir == 'D') {
			D[x].insert(y);
			D2[x + y].insert(y);
			D3[x - y].insert(y);
		}
		if (dir == 'L') {
			L[y].insert(x);
			L2[x + y].insert(y);
			L3[x - y].insert(y);
		}
		if (dir == 'R') {
			R[y].insert(x);
			R2[x + y].insert(y);
			R3[x - y].insert(y);
		}
	}
	int dis = INT_MAX, dis2 = INT_MAX;
	for (auto m : U) {
		set<int> up = m.second;
		set<int> down = D[m.first];
		for (auto y : up) {
			auto it = down.lower_bound(y);
			if (it == down.end()) {
				break;
			}
			else {
				dis = min(dis, (*it) - y);
			}
		}
	}
	for (auto m : R) {
		set<int> right = m.second;
		set<int> left = L[m.first];
		for (auto x : right) {
			auto it = left.lower_bound(x);
			if (it == left.end()) {
				break;
			}
			else {
				dis = min(dis, (*it) - x);
			}
		}
	}
	for (auto m : L2) {
		int sum = m.first;
		set<int> left = m.second;
		for (auto y : left) {
			set<int> down = D2[sum];
			auto it = down.lower_bound(y);
			if (it == down.end()) {
				break;
			}
			else {
				dis2 = min(dis2, (*it) - y);
			}
		}
	}
	for (auto m : R3) {
		int diff = m.first;
		set<int> right = m.second;
		for (auto y : right) {
			set<int> down = D3[diff];
			auto it = down.lower_bound(y);
			if (it == down.end()) {
				break;
			}
			else {
				dis2 = min(dis2, (*it) - y);
			}
		}
	}
	for (auto m : U2) {
		int sum = m.first;
		set<int> up = m.second;
		for (auto y : up) {
			set<int> right = R2[sum];
			auto it = right.upper_bound(y);
			if (it == right.end()) {
				break;
			}
			else {
				dis2 = min(dis2, (*it) - y);
			}
		}
	}
	for (auto m : U3) {
		int diff = m.first;
		set<int> up = m.second;
		for (auto y : up) {
			set<int> left = L3[diff];
			auto it = left.upper_bound(y);
			if (it == left.end()) {
				break;
			}
			else {
				dis2 = min(dis2, (*it) - y);
			}
		}
	}
	if (dis == INT_MAX && dis2 == INT_MAX) {
		cout << "SAFE" << endl;
	}
	else {
		int ans = INT_MAX;
		if (dis != INT_MAX) {
			ans = min(ans, dis * 5);
		}
		if (dis2 != INT_MAX) {
			ans = min(ans, dis2 * 10);
		}
		cout << ans << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T_ = 1;
	//cin >> T_;
	for (int i = 0; i < T_; i++)solve();
	return 0;
}


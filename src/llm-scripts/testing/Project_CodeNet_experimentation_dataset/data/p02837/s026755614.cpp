#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n;
	cin >> n;
	vector<vector<P>>lis(n);
	rep(i, n) {
		int a;
		cin >> a;
		rep(j, a) {
			int x, y;
			cin >> x >> y;
			x--;
			lis[i].push_back(P(x, y));
		}
	}
	int ans(0);
	for (int bit = 0; bit < (1 << n); ++bit) {
		int c = 0;
		int can = 0;
		rep(i, n) {
			int cnt(0);
			int a = lis[i].size();
			if (!(bit >> i & 1))continue;
			can++;
			rep(j, lis[i].size()) {
				int x = lis[i][j].first; int y = lis[i][j].second;
				if ((bit >> x & 1) && y != 1)cnt++;
				if (!(bit >> x & 1) && y == 1)cnt++;
			}
			if (cnt >= 1)c = -1;
		}
		//cout << bit << can << endl;
		if (c != -1) {
			ans = max(can, ans);
		}
		
	}
	cout << ans;
	return 0;
}

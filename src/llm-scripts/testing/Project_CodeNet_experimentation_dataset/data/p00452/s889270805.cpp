#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;

signed main() {
	int n, m;
	while (cin >> n >> m, n || m) {
		vector<int>v(n + 1, 0), Q; rep(i, 1, n + 1)cin >> v[i];
		rep(i, 0, n + 1) {
			rep(j, i, n + 1) {

				if (v[i] + v[j] <= m)Q.push_back(v[i] + v[j]);
			}
		}
		sort(all(Q));
		dumpc(Q);
		int ans(0);
		rep(i, 0, Q.size()) {
			int l = 0, r = Q.size();
			while (r - l > 1) {
				int mid = (l + r) / 2;
				if (Q[mid] > m - Q[i])r = mid;
				else l = mid;
			}
			if (Q[i] + Q[l] <= m)ans = max(ans, Q[i] + Q[l]);
			dump(ans);
		}
		cout << ans << endl;
	}
	return 0;
}
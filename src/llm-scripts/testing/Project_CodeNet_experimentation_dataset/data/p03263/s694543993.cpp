#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<vector<int>> mp(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> mp[i][j];
	vector<tuple<int, int, int, int>> ans;
	rep(i, h) {
		if (i % 2 == 0) {
			for (int j = 0; j < w; ++j) {
				if (mp[i][j] % 2 == 1) {
					if (j + 1 < w) {
						mp[i][j + 1]++;
						ans.emplace_back(i + 1, j + 1, i + 1, j + 2);
					}
					else if (i + 1 < h) {
						mp[i + 1][j]++;
						ans.emplace_back(i + 1, j + 1, i + 2, j + 1);
					}
				}
			}
		}
		else {
			for (int j = w - 1; j >= 0; --j) {
				if (mp[i][j] % 2 == 1) {
					if (j - 1 >= 0) {
						mp[i][j - 1]++;
						ans.emplace_back(i + 1, j + 1, i + 1, j);
					}
					else if (i + 1 < h) {
						mp[i + 1][j]++;
						ans.emplace_back(i + 1, j + 1, i + 2, j + 1);
					}
				}
			}
		}
	}
	int sz = ans.size();
	cout << sz << endl;
	for (auto c : ans) printf("%d %d %d %d\n", get<0>(c), get<1>(c), get<2>(c), get<3>(c));
	return 0;
}
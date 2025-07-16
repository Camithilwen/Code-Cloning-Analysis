/**
*    author:  boutarou
*    created: 10.06.2020 20:12:43
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define fcout cout << fixed << setprecision(15)
using lint = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const long long MOD = 1e9 + 7;
const long long INF = 3e18;
const double PI = 3.1415926535897932;

int n;
vector<P> a, b;
int ans = 0;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		a.push_back({x, y});
	}
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		b.push_back({x, y});
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	rep(i, n) {
		int now_x = b[i].first, now_y = b[i].second;
		int ma_y = -1;
		rep(j, n) {
			if (a[j].first > now_x) break;
			if (a[j].second < now_y) {
				chmax(ma_y, a[j].second);
			}
		}
		if (ma_y == -1) continue;
		ans++;
		rep(j, n) {
			if (a[j].second == ma_y) {
				a.erase(a.begin() + j);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
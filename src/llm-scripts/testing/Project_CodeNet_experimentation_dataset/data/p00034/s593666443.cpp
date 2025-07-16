#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb emplace_back

using pii = pair<int, int>;
using vi = vector<int>;
using lint = long long;

const int inf = 1001001001;
const lint linf = 1001001001001001001ll;
const int mod = 1e9 + 7;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; } return a > b; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; } return a < b; }
template<typename T> inline void print(const T &x, string s = "\n") { cout << x << s; }
template<typename T> inline void print(const vector<T> &v, string s = " ") 
{ rep(i, v.size()) cout << v[i] << (i + 1 == v.size() ? "\n" : s); }
inline bool inside(int y, int x, int H, int W) { return 0 <= y && y < H && 0 <= x && x < W; }
inline lint in() { lint x; std::cin>>x; return x; }

int main() {
	int l[10], u, v;
	char c;

	while (cin >> l[0] >> c) {
		rep(i, 9) cin >> l[i + 1] >> c;
		cin >> u >> c >> v;

		for (int i = 1; i < 10; ++i) {
			l[i] += l[i - 1];
		}

		double d = (double)l[9] / (u + v) * u;
		for (int i = 0; i < 10; ++i) {
			if (l[i] >= d) {
				cout << i + 1 << endl;
				break;
			}
		}
		//rep(i, 10) cout << l[i] << endl;
		//cout << u << endl;
	 	//cout << v << endl;
	}
}
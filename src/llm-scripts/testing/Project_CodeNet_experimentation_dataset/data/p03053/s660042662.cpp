#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}
	queue<P<int>> que;
	VV dist(h, V(w, upper));
	rep(i, h) rep(j, w) {
		if (s[i][j] == '#') {
			que.push(make_pair(i, j));
			dist[i][j] = 0;
		}
	}
	while (!que.empty()) {
		P<int> p = que.front();
		que.pop();
		int y = p.first;
		int x = p.second;
		rep(dir, 4) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (dist[ny][nx] != upper) continue;
			dist[ny][nx] = dist[y][x] + 1;
			que.push(make_pair(ny, nx));
		}
	}
	int ans = 0;
	rep(i, h) rep(j, w) {
		chmax(ans, dist[i][j]);
	}
	cout << ans << endl;
	return 0;
}
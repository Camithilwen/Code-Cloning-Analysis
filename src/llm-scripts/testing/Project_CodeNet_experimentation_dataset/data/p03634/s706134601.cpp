#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const long double PI = acos(-1);

using Edge = pair<int, ll>;
using Graph = vector<vector<Edge>>;

Graph G;
vector<ll> dist;

void dfs(int cur, int pre, ll sum) {
	dist[cur] = sum;
	
	for (auto to : G[cur]) {
		if (to.first != pre) {
			dfs(to.first, cur, sum + to.second);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n;
	cin >> n;
	
	G.resize(n);
	
	rep(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}

	int q, k;
	cin >> q >> k;
	k--;

	dist.resize(n, 0);

	dfs(k, -1, 0);

	rep(i, q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		out(dist[x] + dist[y]);
	}

	return 0;
}
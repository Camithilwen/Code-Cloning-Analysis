#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

vector<vector<int>> graph(100010, vector<int>());
vector<bool> vis(100010);
vector<int> t(100010, -1);

void dfs(int n, int c, bool &ok) {
	t[n] = c;
	vis[n] = true;
	for (int i : graph[n]) {
		if (vis[i]) {
			if (t[i] == t[n]) {
				ok = false;
			}
			continue;
		}
		dfs(i, c ^ 1, ok);
	}
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, m;
	cin >> n >> m;
	vector<bool> check(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
		check[a] = true;
		check[b] = true;
	}
	int ans = n * n;
	int cnt = n;
	rep(i, n) {
		if (!check[i]) {
			cnt--;
			vis[i] = true;
		}
	}
	ans -= cnt * cnt;
	int x = 0, y = 0;
	rep(i, n) {
		bool oks = true;
		if (!vis[i]) {
			dfs(i, 0, oks);
			if (oks) x++;
			else y++;
		}
	}
	ans += 2 * x + y + 2 * x*(x - 1) + 2 * x*y + y * (y - 1);
	cout << ans << endl;
}
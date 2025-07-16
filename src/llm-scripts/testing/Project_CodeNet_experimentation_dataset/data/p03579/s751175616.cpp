#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	vector<vi> adj(n);
	rep(i,0,m) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vi side(n, -1);
	bool is_bipartite = true;
	queue<int> q;
	q.push(0);
	side[0] = 0;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int u : adj[v]) {
			if(side[u] == -1) {
				side[u] = (side[v] ^ 1);
				q.push(u);
			} else {
				is_bipartite &= (side[u] != side[v]);
			}
		}
	}
	if(is_bipartite) {
		int b, w;
		b = w = 0;
		rep(i,0,n) {
			if(side[i] == 0) {
				b++;
			} else {
				w++;
			}
		}
		cout << (ll)b * w - m << '\n';
	} else {
		cout << (ll)(n-1)*n / 2 - m << '\n';
	}
	return 0;
}

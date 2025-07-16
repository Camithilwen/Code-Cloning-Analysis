#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

vector<int> g[MAXN];
vector<vector<int>> cycles;
int par[MAXN];


void dfs(int u) {
	//$ cerr << u << endl;
	for(int v : g[u]) {
		if(par[v] == -1) {
			par[v] = u;
			dfs(v);
		} else {
			int cur = u;
			vector<int> cyc = {u};
			while(cur != v && par[cur] != -2) {
				cyc.push_back(par[cur]);
				cur = par[cur];
			}
			
			if(cyc.back() == v)
				cycles.push_back(cyc);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
	}
	
	
	for(int i = 0; i < n; i++) {
		memset(par, -1, sizeof par);
		par[i] = -2;
		dfs(i);
	}
	
	
	for(vector<int> v : cycles) {
		set<int> s(v.begin(), v.end());
		bool ok = true;
		for(int i = 0; i < (int) v.size(); i++) {
			int cnt = 0;
			for(int nei : g[v[i]]) {
				if(s.count(nei)) {
					cnt++;
				}
			}
			if(cnt > 1) {
				ok = false;
			}
			//$ cerr << v[i] << " : nei's = " << cnt << endl;
		}
		
		//$ cerr << endl;
		
		if(ok) {
			cout << v.size() << '\n';
			for(int i = 0; i < (int) v.size(); i++) {
				cout << v[i]+1 << '\n';
			}
			return 0;
		}
	}
	
	cout << -1 << endl;
}

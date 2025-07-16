#include <bits/stdc++.h>
using namespace std;

int n, m, pre[1001];
bool vis[1001];
vector<int> adj[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		memset(pre, 0, sizeof(pre));
		stack<pair<int, int>> que;
		que.push({i, 0});
		while(!que.empty()){
			pair<int, int> vtx = que.top();
			que.pop();
			vis[vtx.first] = true;
			pre[vtx.first] = vtx.second;
			for(auto j : adj[vtx.first])
				if(j == i){
					set<int> chn = {i};
					int cur = vtx.first;
					while(cur != i){
						chn.insert(cur);
						cur = pre[cur];
					}
					bool val = true;
					for(auto k : chn){
						int cnt = 0;
						for(auto l : adj[k])
							if(chn.find(l) != chn.end()) cnt++;
						if(cnt > 1) val = false;
					}
					if(val){
						cout << chn.size() << "\n";
						for(auto k : chn) cout << k << "\n";
						return 0;
					}
				}else if(!vis[j]) que.push({j, vtx.first});
		}
	}
	cout << "-1\n";
	return 0;
}
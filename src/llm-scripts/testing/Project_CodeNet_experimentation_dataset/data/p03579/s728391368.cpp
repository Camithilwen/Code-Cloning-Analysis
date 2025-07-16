#include <iostream>
#include <vector>
#include <map>
using namespace std; using P=pair<int,int>; using ll=long long;
const int mx=1e5; vector<vector<int>> v(mx); vector<int> c(mx); int n; bool noco=false;
void dfs(int from, int to, int color) {
	if (from == -1) for(int i=0;i<n;i++) c[i]=-1;
	if (c[to] == 0 || c[to] == 1) {
		if (c[to] != color) noco=true; return;
	} else c[to]=color;
	for(int next:v[to]) {
		if (from == next) continue;
		dfs(to, next, color^1);
	}
}
int main() {
	int m; cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a,b; cin>>a>>b; a--; b--; v[a].push_back(b); v[b].push_back(a);
	}
	dfs(-1,0,0);
	ll w=0,h=0,used=0;
	for(int i=0;i<n;i++) {
		if (c[i] == 0) w++;
		if (c[i] == 1) h++;
	}
	if (noco) {
		for(int i=0;i<n;i++) {
			if (c[i] == -1) continue;
			used+=v[i].size();
		}
		used/=2;
		cout<<(w+h)*(w+h-1)/2-used<<endl;
	} else {
		for(int i=0;i<n;i++) {
			if (c[i] == -1) continue;
			for(int x:v[i]) {
				if (c[i]^1 == c[x]) used++;
			}
		}
		used/=2;
		cout<<w*h-used<<endl;
	}
}
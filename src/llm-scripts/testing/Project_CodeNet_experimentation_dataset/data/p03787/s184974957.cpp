#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> g(100010);
vector<int> check(100010, -1);
bool dfs(int key){
    bool flag=false;
    for(int i=0; i<g[key].size(); ++i){
        if(check[g[key][i]]<0){
            check[g[key][i]]=1-check[key];
            flag |= dfs(g[key][i]);
        }
        else flag |= check[key]==check[g[key][i]];
    }
    return flag;
}

int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<M; ++i){
	    int u, v;
	    cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	long solo=0, matsu=0, other=0;
	for(int i=1; i<=N; ++i){
	    if(check[i]<0){
	        if(g[i].size()<1) ++solo;
	        else{
	            check[i]=0;
	            if(dfs(i)) ++other;
	            else ++matsu;
	        }
	    }
	}
	cout << solo*(2*N-solo)+matsu*matsu+(matsu+other)*(matsu+other) << endl;
	return 0;
}

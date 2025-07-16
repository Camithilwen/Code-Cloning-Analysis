#include <bits/stdc++.h>
using namespace std;
int main(){//priority_queue?
	int n, m;
	cin >> n >> m;
	vector<vector<int>> elist(n), rlist(n);
	vector<int> indeg(n);
	for(int i=0; i<n-1+m; ++i){
		int s, t;
		cin >> s >> t;
        --s; --t;
		elist[s].push_back(t);
		rlist[t].push_back(s);
		++indeg[t];
	}
	queue<int> zeroq;
	for(int i=0; i<n; ++i){
		if(indeg[i]==0) zeroq.push(i);
	}
	vector<int> result, par(n,0);
    while(!zeroq.empty()){
		int u=zeroq.front();
		zeroq.pop();

		result.push_back(u);
        for(int i : elist[u]){
			--indeg[i];
			if(indeg[i]==0){
				zeroq.push(i);
				par[i]=u+1;
			}
		}
	}

	for(int i : par) cout << i << endl;
}
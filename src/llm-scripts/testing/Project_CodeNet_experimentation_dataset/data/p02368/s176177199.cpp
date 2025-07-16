#include <bits/stdc++.h>
#define rep(i,n) for(int (i) = 0; (i) < (n);(i)++)
using namespace std;

const int limit = 100010;
vector<int> graph[2][limit];

void add_edge(int from, int to) {
	graph[0][from].push_back(to);
	graph[1][to].push_back(from);
}


auto scc(int n) {
	vector<int> order(n);
	iota(begin(order), end(order), 0);
	vector<int> comp;

	rep(type, 2) {
		stack<int> stk;
		vector<int> norder;
		vector<int> itr(n, 0);

		comp.assign(n, -1);
		int idx = 0;

		/*
		rep(i, n) cerr << order[i] << " ";
		cerr << endl;
		*/

		for (auto &it : order) {
			if (comp[it] != -1) continue; 
			stk.push(it);
	
			while (!stk.empty()) {
				const int v = stk.top(); 				
				comp[v] = idx;
						
				for(int &i = itr[v]; i < graph[type][v].size();++i){
					const int v2 = graph[type][v][i];
					if (comp[v2] == -1){
						stk.push(v2);
						break;
					}
				}

				if(itr[v] == graph[type][v].size()){
					norder.push_back(v);
					stk.pop();
				}
			}
			idx++;
		}

		if (type == 1) break;
		reverse(begin(norder), end(norder));
		order = norder;
	}

	return make_tuple(order, comp);
}

vector<int> order, comp;

int main(void) {
	int n, m;
	cin >> n >> m;

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
	}

	tie(order, comp) = scc(n);

	
	int q;
	cin >> q;
	rep(loop,q){
		int u,v;
		cin >> u >> v;
		if(comp[u]==comp[v])
			puts("1");
		else
			puts("0");
	}

	return 0;
}
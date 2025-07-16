#include <bits/stdc++.h>

using namespace std;

class StronglyConnectedComponentDecomposition
{
private:
	int V; // ????????°
	vector<vector<int>> G; // ??°???????????£??\???????????¨???
	vector<vector<int>> rG; // ?????????????????????????????°??????
	vector<int> vs; // ??°?????????????????????
	vector<bool> used; // ?????§???????????????

public:
	vector<int> cmp; // ?±????????????£????????????????????????????????????
	StronglyConnectedComponentDecomposition( int N = 0 ) {
		V = N;
		G = vector<vector<int>>( V );
		rG = vector<vector<int>>( V );
		used = vector<bool>( V );
		cmp = vector<int>( V );
	}
	void add_edge( int from, int to ) {
		G[from].push_back( to );
		rG[to].push_back( from );
	}
	void dfs( int v ) {
		used[v] = true;
		for( int i = 0; i < G[v].size(); i++ ) {
			if( !used[G[v][i]] ) dfs( G[v][i] );
		}
		vs.push_back( v );
	}
	void rdfs( int v, int k ) {
		used[v] = true;
		cmp[v] = k;
		for( int i = 0; i < rG[v].size(); i++ ) {
			if( !used[rG[v][i]] ) rdfs( rG[v][i], k );
		}
	}
	int scc() {
		used = vector<bool>( V );
		vs.clear();
		for( int v = 0; v < V; v++ ) {
			if( !used[v] ) dfs( v );
		}
		used = vector<bool>( V );
		int k = 0;
		for( int i = vs.size() - 1; i >= 0; i-- ) {
			if( !used[vs[i]] ) rdfs( vs[i], k++ );
		}
		return k;
	}
};

int main() {
	long long int V, E;
	cin >> V >> E;
	StronglyConnectedComponentDecomposition SCCD( V );
	for( size_t i = 0; i < E; i++ ) {
		int s, t;
		cin >> s >> t;
		SCCD.add_edge( s, t );
	}
	SCCD.scc();
	long long int N;
	cin >> N;
	for( size_t i = 0; i < N; i++ ) {
		int u, v;
		cin >> u >> v;
		cout << (SCCD.cmp[u] == SCCD.cmp[v]) << endl;
	}
	return 0;
}
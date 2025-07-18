#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
using namespace std;
template<typename V,typename Weight>
class Dijekstra {
private:
	struct edge {
		Weight dist;V node;V prev;
		bool operator<(edge const& a) const {
			return dist < a.dist;
		}
		bool operator>(edge const& a) const {
			return dist > a.dist;
		}
	};
	vector<V> trace;
	vector<vector<pair<V,Weight>>> E;
	V sz;
public:
	Weight inf = numeric_limits<Weight>::max();
	vector<Weight> D;
	Dijekstra(V v) :
		E(v),sz(v),D(v,inf),trace(v,numeric_limits<V>::max()) {}

	void addEdgeDirected(V from,V to,Weight dis){
		E[from].push_back(make_pair(to,dis));
	}
	void addEdgeUndirected(V from,V to,Weight dis){
		E[from].push_back(make_pair(to,dis));
		E[to].push_back(make_pair(from,dis));
	}

	V size() {return sz;}
	Weight & operator[] (V n) { if (0 <= n && n < sz) return D[n];} 

	void dijekstra(V start){
		priority_queue<edge,vector<edge>,greater<edge>> que;
		D[start] = 0;
		//trace[start] = start;
		que.push(edge{0,start,start});
		Weight d;V v,prev;
		while(!que.empty()){
			edge cur = que.top();que.pop();
			d = cur.dist;v = cur.node;prev = cur.prev;
			if (D[v] < d) continue; //既により最適が見つかっている
			D[v] = d;trace[v] = prev;
			for(pair<V,Weight> e : E[v]){
				if (D[e.first] <= d + e.second) continue;
				que.push(edge{d+e.second,e.first,v});
			}
		}
	}

	vector<V> show_trace(V start,V goal){ // startからgoalの最短距離上のノード
		vector<V> ret;
		for (V node = goal;node != start;node = trace[node]) ret.push_back(node);
		ret.push_back(start);
		return ret; // 配列の先頭がgoal,末尾がstart
	}
};


int main(void){
	long V,E,R;
	long s,t,d;
	cin >> V >> E >> R;
	Dijekstra<long,long> dij(V);

	REP(i,E){
		cin >> s >> t >> d;
		dij.addEdgeDirected(s,t,d);
	}

	dij.dijekstra(R);
	REP(i,V) {
		if (dij[i] == dij.inf) cout << "INF" << endl;
		else cout << dij[i] << endl;
	}
		
	return 0;
}




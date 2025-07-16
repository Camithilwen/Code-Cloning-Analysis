#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define LOOP(i) while(i--)
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

class ConnectNodeInfo{
	vector<vector<pair<ll,ll>>> graph;
public:
	ConnectNodeInfo(int node_num){
		graph.resize(node_num);
	}
	void AddNonDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
		graph[v].emplace_back(u,w);
	}
	void AddDirectionalConnection(ll u,ll v,ll w){
		graph[u].emplace_back(v,w);
	}
	vector<pair<ll,ll>>& operator[](ll index){
		return graph[index];
	}
	size_t size(){return graph.size();}
};

class RootedNode{
public:
	vector<ll> parent;
	ll depth,dist;
	RootedNode():depth(0),dist(0){}
};

class RootedTree{
	int parent_size;
	vector<int> pre,low;
	int pre_count{0};

	void DFS(ConnectNodeInfo& connection,ll child,ll parent,ll dep,ll dist){
		pre[child] = low[child] = pre_count++;

		node[child].parent[0] = parent;
		node[child].depth = dep;
		node[child].dist = dist;

		bool isArticulation = false;
		int ct = 0;

		for(int i = 0;i < connection[child].size();i++){
			ll next_child = connection[child][i].first;
			if(pre[next_child]<0){
				ct++;
				DFS(connection,next_child,child,dep+1,dist+connection[child][i].second);
				low[child] = min(low[next_child],low[child]);
				if (~parent && pre[child] <= low[next_child]) isArticulation = true;
				if (pre[child]<low[next_child]) bridge.emplace_back(min(child,next_child),max(child,next_child));
			}
			else if(next_child != parent){
				low[child] = min(low[child],pre[next_child]);
			}
		}

		if(parent==-1 && ct>1) isArticulation = true;
		if(isArticulation) articulation.push_back(child);
	}
public:
	vector<RootedNode> node;
	vector<pair<ll,ll>> bridge;
	vector<ll> articulation;

	RootedTree(ConnectNodeInfo& connection){
		auto connection_size = connection.size();
		parent_size = 1;
		while((1LL<<parent_size)<connection_size) parent_size++;

		node.resize(connection_size);
		pre.resize(connection_size,-1);
		low.resize(connection_size);
		for(auto& x:node) x.parent.resize(parent_size,-1);
		DFS(connection,0,-1,0,0);
		for(int k=0;k<parent_size-1;k++){
			for(int v=0,ev=connection_size;v<ev;v++){
				if(node[v].parent[k] < 0) node[v].parent[k+1] = -1;
				else node[v].parent[k+1] = node[node[v].parent[k]].parent[k];
			}
		}
	}
	ll FindLCA(ll u,ll v){
		if(node[u].depth > node[v].depth) swap(u,v);
		for(int k=0;k<parent_size;k++){
			if((node[v].depth - node[u].depth) & (1LL<<k)){
				v = node[v].parent[k];
			}
		}
		if(u==v) return u;
		for(int k=parent_size-1;k>=0;k--){
			if(node[u].parent[k] != node[v].parent[k]){
				u = node[u].parent[k];
				v = node[v].parent[k];
			}
		}
		return node[u].parent[0];
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),M=in();
	ConnectNodeInfo connect(N);
	REP(i,M){
		int u=in(),v=in();
		connect.AddNonDirectionalConnection(u,v,1);
	}
	RootedTree tree(connect);
	sort(ALL(tree.articulation));
	for(auto& x:tree.articulation){
		out(x);
	}
	return 0;
}


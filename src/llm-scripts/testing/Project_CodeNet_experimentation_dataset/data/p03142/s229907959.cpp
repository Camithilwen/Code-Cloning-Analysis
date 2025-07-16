#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N=in(),M=in();
	ConnectNodeInfo connect(N);
	vector<int> input(N,0);
	REP(i,N-1+M){
		int u=in()-1,v=in()-1;
		connect.AddDirectionalConnection(u,v,1);
		input[v]++;
	}
	
	stack<int> vertex;
	vector<int> sorted;
	REP(i,N){
		if(input[i]==0){
			vertex.push(i);
			break;
		}
	}
	while(!vertex.empty()){
		auto v=vertex.top();
		vertex.pop();
		sorted.push_back(v);
		for(auto& x:connect[v]){
			input[x.first]--;
			if(!input[x.first]) vertex.push(x.first);
		}
	}
	vector<int> parent(N,-1);
	REP(i,N){
		for(auto& x:connect[sorted[i]]){
			parent[x.first] = sorted[i];
		}
	}

	for(auto& x:parent){
		out(x+1);
	}
	return 0;
}

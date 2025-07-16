#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define FOR(i,c,num) for(ll (i)=(c);(i)<(num);++(i))
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){T x; cin >> x; return (x);}
template<typename T=ll,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>
bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

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
vector<ll> TopologicalSort(ConnectNodeInfo& connect){
	int N=connect.size();
	stack<ll> vertex;
	vector<ll> input(N),sorted;
	REP(i,N){
		for(auto& x:connect[i]) input[x.first]++;
	}
	REP(i,N){
		if(input[i]==0) vertex.push(i);
	}
	while(!vertex.empty()){
		auto v=vertex.top();vertex.pop();
		sorted.push_back(v);
		for(auto& x:connect[v]){
			input[x.first]--;
			if(!input[x.first]) vertex.push(x.first);
		}
	}
	if(sorted.size()!=N) sorted.clear();
	return sorted;
}

ll CalcLongestPathOnDAG(ConnectNodeInfo& connect,vector<ll>& DAG){
	int N=connect.size();
	vll dist(N,-1);
	ll maxD=0;
	REP(i,N){
		if(dist[DAG[i]]<0) dist[DAG[i]] = 0; 
		for(auto& x:connect[DAG[i]]){
			dist[x.first] = max(dist[x.first],dist[DAG[i]]+x.second);
			maxD = max(maxD,dist[x.first]);
		}
	}
	return maxD;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in();
	vvll L(N,vll(N,-1));
	int index=0;
	REP(i,N){
		FOR(j,i+1,N){
			L[i][j] = index++;
			L[j][i] = L[i][j];
		}
	}
	ConnectNodeInfo connect(index);
	REP(i,N){
		ll s=in()-1;
		REP(j,N-2){
			ll t=in()-1;
			connect.AddDirectionalConnection(L[i][s],L[i][t],1);
			s = t;
		}
	}
	auto DAG = TopologicalSort(connect);
	if(DAG.empty()){
		out(-1);
		return 0;
	}

	ll maxD = CalcLongestPathOnDAG(connect,DAG);
	out(maxD+1);
	return 0;
}

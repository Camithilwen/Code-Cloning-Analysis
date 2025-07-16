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

class UnionFind{
	vector<ll> rank;
	vector<ll> diff_weight;
	vector<ll> num;
public:
	vector<ll> par;

	UnionFind(ll N):par(N),num(N),rank(N),diff_weight(N){
		for(ll i=0;i<N;i++){
			par[i]=i;
			num[i]=1;
			rank[i]=0;
			diff_weight[i]=0;
		}
	}

	ll root(ll x){
		if(par[x]==x){
			return x;
		}
		ll r = root(par[x]);
		diff_weight[x]+=diff_weight[par[x]];
		return par[x]=r;
	}

	void unite(ll x,ll y){
		ll rx = root(x);
		ll ry = root(y);
		if (rx == ry) return;
		if(rank[rx]<rank[ry]) swap(rx,ry);
		if(rank[rx]==rank[ry]) ++rank[rx];
		par[ry] = rx;
		num[rx] += num[ry];
	}

	void relate(ll x,ll y,ll w){
		w+=weight(x),w-=weight(y);
		ll rx = root(x);
		ll ry = root(y);
		if (rx == ry) return;
		if(rank[rx]<rank[ry]){
			swap(rx,ry);
			w = -w;
		}
		if(rank[rx]==rank[ry]) ++rank[rx];
		par[ry] = rx;
		diff_weight[ry] = w;
		num[rx] += num[ry];
	}

	bool same(ll x,ll y){
		ll rx = root(x);
		ll ry = root(y);
		return rx == ry;
	}

	ll getsize(ll x){
		return num[root(x)];
	}

	ll weight(ll x){
		root(x);
		return diff_weight[x];
	}

	ll diff(ll x,ll y){
		return weight(y)-weight(x);
	}
};

void FirstDFS(int child,int& post_count,vector<int>& post,ConnectNodeInfo& connect,vector<int>& memo){
	memo[child] = 1;
	for(auto& x:connect[child]){
		if(!memo[x.first]){
			FirstDFS(x.first,post_count,post,connect,memo);
		}
	}
	post[child] = post_count++;
}

void SecondDFS(int start,int child,ConnectNodeInfo& connect,UnionFind& uf,vector<int>& memo){
	uf.unite(start,child);
	memo[child] = 1;
	for(auto& x:connect[child]){
		if(!memo[x.first]){
			SecondDFS(start,x.first,connect,uf,memo);
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),M=in();
	ConnectNodeInfo connect(N),inverse_connect(N);
	REP(i,M){
		int u=in(),v=in();
		connect.AddDirectionalConnection(u,v,1);
		inverse_connect.AddDirectionalConnection(v,u,1);
	}

	int post_count=0;
	vector<int> post(N,-1);
	vector<int> memo(N,0);
	REP(i,N){
		if(!memo[i]) FirstDFS(i,post_count,post,connect,memo);
	}
	vector<pair<int,int>> new_order(N);
	REP(i,N){
		new_order[i].first=i;
		new_order[i].second=post[i];
	}
	sort(ALL(new_order),PAIRCOMP(second,>));
	UnionFind uf(N);

	fill(ALL(memo),0);
	REP(i,N){
		if(!memo[new_order[i].first]) SecondDFS(new_order[i].first,new_order[i].first,inverse_connect,uf,memo);
	}
	
	int Q=in();
	LOOP(Q){
		int u=in(),v=in();
		out(uf.same(u,v)?1:0);
	}
	return 0;
}


#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef struct{
	int x,y,id;
} ii;
typedef tuple<int,ii,ii> t;
int dist(ii a,ii b){
	return min(abs(a.x-b.x),abs(a.y-b.y));
}
vector<int> up;
int fp(int u){
	if(up[u]<0) return u;
	else return up[u] = fp(up[u]);
}
void unite(int u,int v){
	int x = fp(u);
	int y = fp(v);
	if(x!=y) up[x]=y;
}
signed main() {
	int n;
	cin>>n;
	up.resize(n,-1);
	vector<ii> p(n);
	int i=0;
	for(auto &v:p)
	{
		v.id=i++;
		cin>>v.x>>v.y;
	}
	auto cmp= [](t a,t b){
		return get<0>(a)>get<0>(b);
	};
	priority_queue<t,vector<t>,decltype (cmp)> pq(cmp);
	sort(p.begin(),p.end(),[](ii lhs,ii rhs){return lhs.x<rhs.x;});
	for(auto it = p.begin();it!=prev(p.end());it++){
		int d = dist(*it,*next(it));
		pq.push(make_tuple(d,*it,*next(it)));
	}
	sort(p.begin(),p.end(),[](ii lhs,ii rhs){return lhs.y<rhs.y;});
		for(auto it = p.begin();it!=prev(p.end());it++){
			int d = dist(*it,*next(it));
			pq.push(make_tuple(d,*it,*next(it)));
		}
	int cnt = n;
	int res = 0;
	while(!pq.empty()){
		int d;
		ii a,b;
		tie(d,a,b) = pq.top();
		pq.pop();
		if(fp(a.id)!=fp(b.id)){
			n--;
			res+=d;
			unite(fp(a.id), fp(b.id));
		}
	}
	cout<<res<<endl;
}
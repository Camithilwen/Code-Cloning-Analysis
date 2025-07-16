#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
vector<P>vec;
int p[200005],q[200005],c[200005];
vector<P>edge[600105];
int dist[600105];
bool used[600105];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&p[i],&q[i],&c[i]);
		vec.pb(mp(p[i],c[i]));
		vec.pb(mp(q[i],c[i]));
	}
	SORT(vec); ERASE(vec);
	for(int i=0;i<vec.size();i++){
		int v = vec[i].fi;
		int ty = vec[i].sc;
		edge[v+500050].pb(mp(i,1));
		edge[i].pb(mp(v+500050,1));
	}
	for(int i=0;i<m;i++){
		int A = POSL(vec,mp(p[i],c[i]));
		int B = POSL(vec,mp(q[i],c[i]));
		edge[A].pb(mp(B,0));
		edge[B].pb(mp(A,0));
	}
	fill(dist,dist+600105,INF);
	dist[500051] = 0;
	deque<int>deq;
	deq.pb(500051);
	while(deq.size()){
		int q = deq.front(); deq.pop_front();
		if(used[q]) continue;
		used[q] = 1;
		for(int i=0;i<edge[q].size();i++){
			if(used[edge[q][i].fi]) continue;
			if(dist[edge[q][i].fi] > dist[q]+edge[q][i].sc){
			    dist[edge[q][i].fi] = dist[q]+edge[q][i].sc;
    			if(edge[q][i].sc == 0){
    				deq.push_front(edge[q][i].fi);
    			}
    			else{
    				deq.push_back(edge[q][i].fi);
    			}
			}
		}
	}
	if(dist[500050+n] == INF) cout << -1 << endl;
	else cout << (2+dist[500050+n])/2-1 << endl;
}
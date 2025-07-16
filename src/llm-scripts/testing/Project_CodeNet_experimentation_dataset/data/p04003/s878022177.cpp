#include<bits/stdc++.h>
#define MAXN 1000005
#define INF int(16843009)
using namespace std;

int N,M;

struct edge{
	int u,v;
	edge(int u=0, int v=0):u(u), v(v){}
};

vector<edge> adjc[MAXN];
vector<int> adj1[MAXN];

void addE(int u, int v){
	cerr<<"addE: "<<u<<" "<<v<<endl;
	adj1[u].push_back(v);
	adj1[v].push_back(u);
}

int d[MAXN];
void bfs(){
	memset(d, 1, sizeof(d));
	d[1] = 0;
	queue<int> q;
	q.push(1);
	
	int u,v;
	while(!q.empty()){
		u = q.front(); q.pop();
		if(u==N) return;
		
		for(int k=0;k<adj1[u].size();k++){
			v = adj1[u][k];
			if(d[u] + 1 < d[v]){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

int fa[MAXN];
int p[MAXN];
int findR(int x){
	if(p[x]==x) return x;
	else return p[x] = findR(p[x]);
}

int main(){
	
	scanf("%d%d", &N, &M);
	
	int u,v,c;
	for(int i=1;i<=M;i++){
		scanf("%d%d%d", &u, &v, &c);
		adjc[c].push_back(edge(u,v));
	}
	
	int top = N;
	for(int i=1;i<=1e6;i++){
		//cout<<i<<endl;
		if(adjc[i].size()==0) continue;
		//
		for(int k=0;k<adjc[i].size();k++){
			u = adjc[i][k].u; v = adjc[i][k].v;
			p[u] = u; p[v] = v;
			fa[u] = fa[v] = 0;
		}
		
		int ru,rv; 
		for(int k=0;k<adjc[i].size();k++){
			u = adjc[i][k].u; v = adjc[i][k].v;
			ru = findR(u); rv = findR(v);
			p[ru] = rv;
		}
		
		for(int k=0;k<adjc[i].size();k++){
			u = adjc[i][k].u; v = adjc[i][k].v;
			ru = findR(u); rv = findR(v);
			//
			if(fa[ru]) addE(u,fa[ru]);
			else{
				fa[ru] = ++top;
				addE(u,top);
			}
			
			//
			if(fa[rv]) addE(v,fa[rv]);
			else{
				fa[rv] = ++top;
				addE(v,top);
			}
		}
	}
	//cout<<"pass"<<endl;
	bfs();
	
	if(d[N]==INF) cout<<"-1"<<endl;
	else cout<<d[N]/2<<endl;
	
	return 0;
}

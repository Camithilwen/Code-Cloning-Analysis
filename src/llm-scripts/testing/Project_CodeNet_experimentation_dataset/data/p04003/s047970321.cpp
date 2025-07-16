//beet

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
#define MAX 114514
vector<P> G[MAX*5];
map<int,int> M[MAX];
int dist[MAX*5];
signed main(){
  int n,m;
  cin>>n>>m;
  int cnt=n;
  for(int i=0;i<m;i++){
    int p,q,c;
    cin>>p>>q>>c;
    p--;q--;
    auto add_edge = [&](int x){
      if(!M[x].count(c)){
	M[x][c]=cnt++;
	G[M[x][c]].push_back(P(x,0));
	G[x].push_back(P(M[x][c],1));
      }
    };
    add_edge(p);
    add_edge(q);
    G[M[p][c]].push_back(P(M[q][c],0));
    G[M[q][c]].push_back(P(M[p][c],0));
  }
  memset(dist,-1,sizeof(dist));
  priority_queue<P,vector<P>,greater<P> > q;
  dist[0]=0;
  q.push(P(dist[0],0));
  while(!q.empty()){
    P p=q.top();q.pop();
    int d=p.first,v=p.second;
    if(dist[v]<d) continue;
    for(P e:G[v]){
      int u=e.first,c=e.second;
      if(dist[u]<0||dist[u]>d+c){
	dist[u]=d+c;
	q.push(P(dist[u],u));
      }
    }
  }
  cout<<dist[n-1]<<endl;
  return 0;
}

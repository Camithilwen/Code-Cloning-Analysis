#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N_MAX=100001;
long long INF = 123456789123456789;
typedef pair<long long,int> P;
void dijkstra(int s, int V, vector<P>* g, long long* d){
  if(d[s]==0)
    return;
  int i,v;
  P p,e;
  priority_queue<P, vector<P>, greater<P>> que; // 最短距離，頂点番号
  fill(d,d+V,INF);
  d[s]=0;
  que.push(P(0,s));
  while(!que.empty()){
    p=que.top(); que.pop();
    v=p.second;
    if(d[v]<p.first) continue;
    for(i=0;i<g[v].size();i++){
      e=g[v][i];
      if(d[e.second]>d[v]+e.first){
        d[e.second]=d[v]+e.first;
        que.push(P(d[e.second],e.second));
      }
    }
  }
  return;
}
int main()
{
  int n,q,k,x,y,a,b,i;
  long long c;
  long long d[N_MAX];
  vector<P> g[N_MAX];
  cin >> n;
  fill(d+1,d+n+1,INF);
  for(i=0;i<n-1;i++){
    cin >> a >> b >> c;
    g[a].emplace_back(c,b);
    g[b].emplace_back(c,a);
  }
  cin >> q >> k;
  dijkstra(k,n,g,d);
  for(i=0;i<q;i++){
    cin >> x >> y;
    cout << d[x]+d[y] << endl;
  }
  return 0;
}
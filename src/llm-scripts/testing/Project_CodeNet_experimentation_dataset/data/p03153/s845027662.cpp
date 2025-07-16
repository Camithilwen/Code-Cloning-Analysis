#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
 
const int MAXN = 400100;
vector<PII> graph[MAXN];
 
void add_edge(int v, int u, int c) {
  graph[v].push_back(PII(u,c));
  graph[u].push_back(PII(v,c));
}
 
 
int main() {
  int N, D;
  cin >> N >> D;
  for(int i=0; i<N; i++) {
    LL p;
    cin >> p;
    add_edge(i, i+N, p);
  }
 
  for(int i=0; i<N-1; i++) {
    int v,u,c;
    //cin >> v >> u >> c;
    //v--;u--;
    add_edge(i, i+1, D);
  }
 
  priority_queue<pair<LL,PII> , vector<pair<LL,PII> >, greater<pair<LL,PII> > > pq;
  vector<int> used(2*N, 0), dist(2*N, 0);
  int cnt = 1;
  LL ans = 0;
  for(int i=0; i<N; i++) {
    pq.push(make_pair(0, PII(i+N, -1)));
  }
  while(!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    LL v = cur.second.first;
    if(used[v]) {
      LL u = cur.second.second;
      if(used[v] > used[u])
	ans += dist[v] + cur.first;
      continue;
    }
    used[v] = cnt;
    cnt++;
    dist[v] = cur.first;
    for(auto uc: graph[v]) {
      LL u = uc.first;
      LL c = uc.second;
      pq.push(make_pair(dist[v] + c, PII(u, v)));
    }
    
  }
  cout << ans << endl;
  
  return 0;
}
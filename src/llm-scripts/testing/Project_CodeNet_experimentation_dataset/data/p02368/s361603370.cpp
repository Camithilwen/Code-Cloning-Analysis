#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V;
vector<int>G[10000],rG[10000],vs;
bool used[10000];
int cmp[10000];

void add_edge(int from,int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v]=true;
  for(int i=0;i<G[v].size();i++){
    if(!used[G[v][i]])dfs(G[v][i]);
  }
  vs.push_back(v);
}

void rdfs(int v,int k){
  used[v]=true;
  cmp[v]=k;
  for(int i=0;i<rG[v].size();i++){
    if(!used[rG[v][i]])rdfs(rG[v][i],k);
  }
}

int scc(void){
  fill(used,used+V,0);
  vs.clear();
  for(int v=0;v<V;v++)if(!used[v])dfs(v);

  fill(used,used+V,0);
  int k=0;
  for(int i=vs.size()-1;i>=0;i--){
    if(!used[vs[i]])rdfs(vs[i],k++);
  }
  return k;
}

int main(void){
  int m,q,a,b;

  cin >> V >> m;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    add_edge(a,b);
  }

  scc();

  cin >> q;
  for(int i=0;i<q;i++){
    cin >> a >> b;
    cout << (cmp[a]==cmp[b]) << endl;
  }

  return 0;
}
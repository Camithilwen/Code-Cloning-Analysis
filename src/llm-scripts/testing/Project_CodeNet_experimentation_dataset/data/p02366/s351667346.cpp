#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> articulation_points;
vector<int> graph[100000];
int ord[100000],low[100000];
bool visited[100000];

int visit_time = 0;

void dfs(int v,int p){
  visited[v] = true;
  ord[v] = visit_time;
  low[v] = ord[v];
  visit_time++;
  bool is_articulation = false;
  int cnt = 0;
  for(int i=0;i<graph[v].size();++i){
    if(!visited[graph[v][i]]){
      cnt++;
      dfs(graph[v][i],v);
      low[v] = min(low[v],low[graph[v][i]]);
      if(p!=-1&&ord[v]<=low[graph[v][i]]) is_articulation = true;
    }else if(graph[v][i]!=p){
      low[v] = min(low[v],ord[graph[v][i]]);
    }
  }

  if(p==-1&&cnt > 1) is_articulation = true;
  if(is_articulation) articulation_points.emplace_back(v);
}

int main(){
  int N , M ;
  cin >> N >> M;
  for(int i=0;i<M;++i){
    int s,t;
    cin >> s >> t;
    graph[s].push_back(t);   
    graph[t].push_back(s);
  }
  
  for(int i=0;i<N;++i){
    if(!visited[i]) dfs(i,-1);
  }
  
  sort(articulation_points.begin(),articulation_points.end());
  for(const auto &a:articulation_points){
    cout << a << endl;
  }
  return 0;
}
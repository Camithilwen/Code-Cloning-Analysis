#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;

void dfs(int u, int prev, int *cnt, int *visited, int *prenum, int *lowest, int *parent, vector< vector<int> > &v){
  visited[u] = true;
  prenum[u] = lowest[u] = *cnt;
  REP(i, v[u].size()){
    int next = v[u][i];
    if(!visited[next]){
      parent[next] = u;
      ++(*cnt);
      dfs(next, u, cnt, visited, prenum, lowest, parent, v);
      lowest[u] = min(lowest[u], lowest[next]);
    } else if(next != prev)
      lowest[u] = min(lowest[u], prenum[next]);
  }
}

vector<int> articulation_points(int V, int E, vector< vector<int> > &v){
  int visited[V], prenum[V], lowest[V], parent[V];
  memset(visited, 0, sizeof(visited));
  parent[0] = -1;
  int tmp = 1;
  dfs(0, -1, &tmp, visited, prenum, lowest, parent, v);
  //cout <<"prenum" <<endl;
  //REP(i, V) cout <<i <<" : " <<prenum[i] <<endl;
  //cout <<"parent" <<endl;
  //REP(i, V) cout <<i <<" : " <<parent[i] <<endl;
  //cout <<"lowest" <<endl;
  //REP(i, V) cout <<i <<" : " <<lowest[i] <<endl;
  vector<int> ret;
  int cnt = 0, used[V];
  memset(used, 0, sizeof(used));
  FOR(i, 1, V){
    if(parent[i] == 0) ++cnt;
    if(parent[i] > 0 && !used[parent[i]] && prenum[parent[i]] <= lowest[i]){
      used[parent[i]] = true;
      ret.push_back(parent[i]);
    }
  }
  if(cnt >= 2) ret.push_back(0);
  return ret;
}

int main() {
  int V, E; cin >>V >>E;
  vector< vector<int> > es(V);
  REP(i, E){
    int f, t; cin >>f >>t;
    es[f].push_back(t);
    es[t].push_back(f);
  }
  vector<int> ans = articulation_points(V, E, es);
  SORT(ans);
  REP(i, ans.size()) cout <<ans[i] <<endl;
  return 0;
}
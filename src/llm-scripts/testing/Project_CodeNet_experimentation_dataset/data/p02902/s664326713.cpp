#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
vector <int> edges[1000];
vector <int> cycle;
bool in_stack[1000];
bool done[1000];
set <pair <int, int> > edge_set;
int cycle_begin;
bool dfs_cycle(int cur){
  in_stack[cur] = true;
  cycle.push_back(cur);
  done[cur] = true;
  for(int i = 0; i < edges[cur].size(); i++){
    int next = edges[cur][i];
    if(in_stack[next]){
      cycle_begin = next;
      return true;
    } else {
      if(!done[next] && dfs_cycle(next)){
        return true;
      }
    }
  }
  cycle.pop_back();
  in_stack[cur] = false;
  return false;
}

int main(void){
  int N;
  int M;
  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int a;
    int b;
    cin >> a >> b;
    edges[a - 1].push_back(b - 1);
    edge_set.insert(make_pair(a - 1, b - 1));
  }
  for(int i = 0; i < N; i++){
    if(!done[i]){
      if(dfs_cycle(i)){
        break;
      }
    }
  }

  if(cycle.size() == 0){
    cout << -1 << endl;
    return 0;
  }

  vector <int> new_cycle;
  for(int i = 0; i < cycle.size(); i++){
    if(cycle[i] == cycle_begin){
      for(int j = i; j < cycle.size(); j++){
        new_cycle.push_back(cycle[j]);
      }
      break;
    }
  }
  cycle = new_cycle;
  while(true){
    map <int, int> cycle_map;
    for(int i = 0; i < cycle.size(); i++){
      cycle_map[cycle[i]] = i;
      //cout << cycle[i] << " ";
    }
    //cout << endl;
    bool updated = false;
    for(int u = 0; u < N; u++){
      for(int j = 0; j < edges[u].size(); j++){
        int v = edges[u][j];
        if(cycle_map.find(u) != cycle_map.end() 
          && cycle_map.find(v) != cycle_map.end() 
          && (cycle_map[u] + 1) % cycle.size() != cycle_map[v]){
          vector <int> next_cycle;
          if(cycle_map[u] > cycle_map[v]){
            for(int k = cycle_map[v]; k <= cycle_map[u]; k++){
              next_cycle.push_back(cycle[k]);
            }
          } else {
            for(int k = cycle_map[v]; k < cycle.size(); k++){
              next_cycle.push_back(cycle[k]);
            }
            for(int k = 0; k <= cycle_map[u]; k++){
              next_cycle.push_back(cycle[k]);
            }
          }
          cycle = next_cycle;
          updated = true;
          break;
        }
      }
      if(updated){
        break;
      }
    }
    if(!updated){
      break;
    }
  }

  cout << cycle.size() << endl;
  for(int i = 0; i < cycle.size(); i++){
    cout << cycle[i] + 1 << endl;
  }

  for(int i = 0; i < cycle.size(); i++){
    if(edge_set.find(make_pair(cycle[i], cycle[(i + 1) % cycle.size()])) == edge_set.end()){
      cout << "shit no edge!" << endl;
    }
    for(int j = 0; j < cycle.size(); j++){
      if(i == j || (i + 1) % cycle.size() == j){
        continue;
      }
      if(edge_set.find(make_pair(cycle[i], cycle[j])) != edge_set.end()){
        cout << "shit" << endl;
      }
    }
  }

  return 0;
}

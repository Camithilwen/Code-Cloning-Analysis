#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int N, M;
vector<int> G[1005];
vector<int> ret;

bool is_valid(const vector<int>& path){
  map<int,int> visited;
  rep(i,path.size()){
    visited[path[i]] = 1;
  }

  vector<int> in(1005, 0);
  rep(i,path.size()){
    int x = path[i];
    rep(j,G[x].size()){
      if(visited[G[x][j]] == 1){
        in[G[x][j]]++;
      }
    }
  }

  rep(i,path.size()){
    int x = path[i];
    if(in[x] > 1) return false;
  }
  return true;
}



void solve(int st){
  vector<int> path;
  
  vector<int> parent(1005, -1);
  parent[st] = st;
  queue<int> que;
  que.push(st);
  while(!que.empty()){
    int v = que.front(); que.pop();
    rep(i,G[v].size()){
      if(G[v][i] == st){
        int x = v;
        while(x != st){
          path.push_back(x);
          x = parent[x];
        }
        path.push_back(st);
        if(!is_valid(path)) return;
        break;
      }else{
        if(parent[G[v][i]] != -1){
        }else{
          parent[G[v][i]] = v;
          que.push(G[v][i]);
        }
      }
      if(path.size() > 0) break;
    }
  }



  if(path.size() == 0) return;
  if(ret.size() == 0 || path.size() < ret.size()){
    ret = path;
  }
}

int main(){
  cin >> N >> M;
  rep(i,M){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }


  
  REP(i,1,N+1){
    solve(i);
  }

  if(ret.size() == 0) cout << -1 << endl;
  else {
    cout << ret.size() << endl;
    rep(i,ret.size()){
      cout << ret[i] << endl;
    }
  }
  return 0;
}


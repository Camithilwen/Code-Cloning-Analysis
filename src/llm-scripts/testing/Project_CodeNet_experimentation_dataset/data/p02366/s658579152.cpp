#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define M 100000

vector<int> G[M];
int N;
bool visited[M];
int prenum[M], parent[M], lowest[M], timer;

void dfs(int current, int prev){
  //?????????current????¨???????????????¨?????????
  prenum[current] = lowest[current] = timer;
  timer++;

  visited[current] = true;

  int next;
  for(int i=0; i<G[current].size(); ++i){
    next = G[current][i];

    if( !visited[next] ){
      //?????????current???????????????next????¨????????????´????????????
      parent[next] = current;

      dfs(next, current);

      //?????????next?????¢?´¢????????????????????¨?????????
      lowest[current] = min(lowest[current], lowest[next]);
    }
    else if( next != prev){ //??¨??????current --> next ???Back-Edge?????´???
      lowest[current] = min(lowest[current], prenum[next]);
    }

  }
  //?????????current ?????¢?´¢????????????????????¨?????????
}

void art_points(){
  for(int i=0; i<N; ++i) visited[i] = false;
  timer=1;

  //lowest????¨????
  dfs(0, -1); //0 == root

  set<int> ap;
  int np=0;
  for(int i=1; i<N; ++i){
    int p = parent[i];
    if(p==0) np++;
    else if(prenum[p] <= lowest[i]) ap.insert(p);
  }

  if(np>1) ap.insert(0);
  for(set<int>::iterator it = ap.begin(); it!=ap.end(); ++it) cout << *it << endl;
}

int main(){
  int m;
  scanf(" %d %d", &N, &m);

  for(int i=0; i<m; ++i){
    int s, t;
    scanf(" %d %d", &s, &t);
    G[s].push_back(t);
    G[t].push_back(s);
  }

  art_points();

}
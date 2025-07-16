#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define debug2(x,y) cout<<"("<<#x<<","<<#y<<") = ("<<(x)<<","<<(y)<<")\n"
using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define rep(i, n) for(int i=0; i<(int)n; i++)

namespace /*DAG.cpp*/{
  int N,M; //頂点と辺の数
  vector<vector<int>> G; //グラフ
  vector<int> h; //入次数 : topoBFS
  vector<int> l_depth; //最大経路長 //recDFSでは探索済みかどうかも示す
  vector<int> s_depth; //最短経路長
  vector<int> ans; //答えを格納(recDFSではreverse必要)

  void input(){
    cin>>N>>M;
    G.resize(N);
    h.resize(N, 0);
    int f,t;
    for(int i=0; i<M; i++){
      cin>>f>>t;
      f--;t--;
      G[f].push_back(t); //recDFSとtopoBFS両方に必要
      h[t]++; //topoBFSにのみ必要
    }
  }

  void topoBFS(){
    l_depth.resize(N, -1);
    s_depth.resize(N, N);
    
    queue<int> unchecked;
    for(int i=0; i<N; i++){
      if(h[i]==0){
        unchecked.push(i);
        l_depth[i] = 0;
        s_depth[i] = 0;
      }
    }
    while(!unchecked.empty()){
      int current = unchecked.front();
      unchecked.pop();
      ans.push_back(current+1);
      for(int next: G[current]){
        h[next]--;

        l_depth[next] = max(l_depth[next], l_depth[current]+1); //最長経路長
        s_depth[next] = min(s_depth[next], s_depth[current]+1); //最短経路長

        if(h[next]==0){
          unchecked.push(next);
        }
      }
    }
  }

  void recDFS(int look){
    if(l_depth[look]!=-1) return;
    if(G[look].size()){
      for(int next: G[look]){
        recDFS(next);
        l_depth[look] = max(l_depth[next]+1, l_depth[look]);
        s_depth[look] = min(s_depth[next]+1, s_depth[look]);
      }
    }else{
      l_depth[look] = 0;
      s_depth[look] = 0;
    }
    ans.push_back(look+1);
  }
}


int main(){
  int n;
  cin>>n;
  vvi IDs(n, vi(n, -1));
  N = n*(n-1)/2;
  G.resize(N);
  h.resize(N, 0);

  int id = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      IDs[i][j] = id;
      IDs[j][i] = id;
      id++;
    }
  }
  /*
  rep(i,n){
    rep(j,n){
      cout<<IDs[i][j]<<",";
    }
    cout<<endl;
  }
  debug(G.size());
  //*/
  int t, bufid, vsid;
  for(int i=0; i<n; i++){
    cin>>t;t--;
    bufid = IDs[i][t];
    for(int j=1; j<n-1; j++){
      cin>>t;t--;
      vsid = IDs[i][t];

      G[bufid].push_back(vsid);
      h[vsid]++;

      bufid = vsid;
    }
  }

  /*
  for(int i=0; i<N; i++){
    debug2(i, h[i]);
  }
  */

  topoBFS();
  /*
  for(int x: ans){
    cout<<x<<",";
  }cout<<" -> ";
  */
  bool isDAG = ans.size()==N;
  //cout<<(isDAG? "閉路なし": "閉路あり")<<endl;
  if(isDAG){
    int l_max = *max_element(l_depth.begin(), l_depth.end());
    cout<<l_max+1<<endl;
  }else{
    cout<<-1<<endl;
  }
}
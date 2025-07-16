#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,u,v; cin>>n>>u>>v;
  vector<vector<int>> t(n+1,vector<int>(0));
  for(int i=0; i<n; ++i){
    int a,b; cin>>a>>b;
    t[a].push_back(b),t[b].push_back(a);
  }
  vector<int> ud(n+1,0),vd(n+1,0);
  vector<bool> d(n+1,true);
  queue<pair<int,int>> q;
  q.push({v,0}); d[v]=false;
  while(!q.empty()){
    int x=q.front().first,y=q.front().second; q.pop();
    vd[x]=y;
    for(auto& i:t[x]) if(d[i]==true) q.push({i,y+1}),d[i]=false;
  }
  int res=0;
  d=vector<bool>(n+1,true);
  q.push({u,0}); d[u]=false;
  while(!q.empty()){
    int x=q.front().first,y=q.front().second; q.pop();
    ud[x]=y; if(vd[x]>ud[x]) res=max(vd[x]-1,res);
    for(auto& i:t[x]) if(d[i]==true) q.push({i,y+1}),d[i]=false;
  }
  cout<<res;
  return 0;
}

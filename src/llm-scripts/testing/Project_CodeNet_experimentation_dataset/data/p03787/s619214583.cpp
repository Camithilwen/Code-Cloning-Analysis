#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<ll>>;
ll N,M;
int main(){
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
  ll u,v;cin>>u>>v;u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }vector<ll>dist(N,-1);
  ll a=0;ll b=0;ll c=0;
  for(int i=0;i<N;i++){
  if(dist[i]==-1){
  bool x=true;
    dist[i]=0;
    queue<ll>que;que.push(i);ll sum=1;
    while(!que.empty()){
    ll u=que.front();
      que.pop();
      for(auto v:G[u]){
      if(dist[v]!=-1 && dist[v]!=dist[u])
        continue;
        else if(dist[v]==dist[u] && x)
          x=false;
        else{
        dist[v]=dist[u]+1;sum++;que.push(v);
        }
      }
     }if(sum==1)b+=1;
    else{
    a++;
      if(x)c++;
    
    }
  
  }
  }ll ans=2*b*(N-b)+(b*b)+(a*a)+(c*c);
  cout<<ans<<endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll h,w;
  cin >> h >> w;
  char c[h][w];
  ll dist[h][w];
  ll ans=0;
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
      dist[i][j]=-1;
      if(c[i][j]=='.'){
        ans++;
      }
    }
  }
  queue<pair<ll,ll>> que;
  que.push(make_pair(0,0));
  int x[4]={1,0,-1,0};
  int y[4]={0,1,0,-1};
  dist[0][0]=0;
  while(!que.empty()){
    auto p=que.front();
    ll cpx=p.first;
    ll cpy=p.second;
    que.pop();
    for(int k=0;k<4;k++){
      int xx=cpx+x[k];
      int yy=cpy+y[k];
      if(xx<0 || xx>=h || yy>=w || yy<0 || c[xx][yy]=='#'){
        continue;
      }
      if(dist[xx][yy]!=-1){
        continue;
      }
      dist[xx][yy]=dist[cpx][cpy]+1;
      que.push(make_pair(xx,yy));
    }
  }
  if(dist[h-1][w-1]==-1){
    cout << -1;
    return 0;
  }
  cout << ans-1-dist[h-1][w-1];
}
  
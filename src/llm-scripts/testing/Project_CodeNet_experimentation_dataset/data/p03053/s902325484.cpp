#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
  int H,W,ans=0; cin>>H>>W;
  vector<vector<char>> S(H,vector<char>(W));
  queue<pair<int,int>> Q;
  vector<vector<bool>> seen(H,vector<bool>(W,false)); 
  rep(i,H){
    rep(j,W){
      cin>>S.at(i).at(j);
      if(S.at(i).at(j)=='#'){
        Q.push(make_pair(i,j));
        seen[i][j]=true;
      }
    }
  }
  Q.push(make_pair(-1,-1));
  while(!Q.empty()){
    int x=Q.front().first,y=Q.front().second;
    Q.pop();
    if(x==-1&&y==-1){
      if(Q.empty())continue;
      ans++;
      Q.push(make_pair(-1,-1));
      continue;  
    }
    rep(j,4){
      int nx=x+dx[j],ny=y+dy[j];
      if(nx<0 || nx>= H || ny<0 || ny>=W) continue;
      if(seen[nx][ny]==false){
      Q.push(make_pair(nx,ny));
      seen[nx][ny]=true;
      }
    }
  }
  cout<<ans;
}

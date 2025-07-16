#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod = 1000000007;

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>s(H);
  for(int i=0;i<H;i++){
    cin>>s[i];
  }
  vector<vector<int>>dist(H,vector<int>(W,-1));
  queue<pair<int,int>>q;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s[i][j]=='#'){q.push(make_pair(i,j));dist[i][j]=0;}
    }
  }
  vector<int>dx={0,0,-1,1};
  vector<int>dy={1,-1,0,0};
  while(!q.empty()){
    auto p=q.front();q.pop();
    int x=p.second,y=p.first;
    for(int k=0;k<4;k++){
      int ny=y+dy[k],nx=x+dx[k];
      if(ny<0||ny>=H||nx<0||nx>=W){continue;}
      if(dist[ny][nx]!=-1){continue;}
      dist[ny][nx]=dist[y][x]+1;
      q.push(make_pair(ny,nx));
    }  
  }
  int MAX=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      chmax(MAX,dist[i][j]);
    }
  }
  cout<<MAX<<endl;
  return 0;
}
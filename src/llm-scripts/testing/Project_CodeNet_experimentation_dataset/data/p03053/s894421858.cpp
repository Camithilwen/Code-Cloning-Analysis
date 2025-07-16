#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using P = pair<int,int>;
const vector<int> di{-1,0,1,0};
const vector<int> dj{0,-1,0,1};

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H,vector<char>(W));
  vector<vector<int>> D(H,vector<int>(W,-1));
  queue<P> q;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> A.at(i).at(j);
      if(A.at(i).at(j)=='#'){
        q.push(make_pair(i,j));
        D.at(i).at(j) = 0;
      }
    }
  }
  while(!q.empty()){
    int i, j;
    tie(i,j) = q.front();
    q.pop();
    for(int v=0; v<4; v++){
      int ni = i+di.at(v);
      int nj = j+dj.at(v);
      if(ni<0||ni>=H) continue;
      if(nj<0||nj>=W) continue;
      if(D.at(ni).at(nj)<0){
        D.at(ni).at(nj) = D.at(i).at(j)+1;
        q.push(make_pair(ni,nj));
      }
    }
  }
  for(int i=0; i<H; i++){
    sort(D.at(i).begin(),D.at(i).end());
  }
  int ans = 0;
  for(int i=0; i<H; i++){
    ans = max(ans,D.at(i).at(W-1));
  }
  cout << ans;
  return 0;
}
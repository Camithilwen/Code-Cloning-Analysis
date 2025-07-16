#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

int main(){
  int H,W;cin >> H >> W;
  vector<string> S(H);
  int cnt=0;
  for(int i=0;i<H;i++){
    cin >> S[i];
    for(int j=0;j<W;j++){
      if(S[i][j]=='#'){
        cnt ++;
      }
    }
  }
  vector<vector<bool>> P(H,vector<bool>(W,false));
  queue<int> X;
  queue<int> Y;
  queue<int> D;
  X.push(0);
  Y.push(0);
  D.push(1);
  P[0][0] = true;
  int goalD=0;
  while(!X.empty()){
    int x = X.front(),y=Y.front(),d=D.front();
    X.pop();Y.pop();D.pop();
    if(x==H-1&&y==W-1){
      goalD = d;
      break;
    }
    if(x-1>=0){
      if(S[x-1][y]=='.'&&!P[x-1][y]){
        X.push(x-1);Y.push(y);D.push(d+1);
        P[x-1][y] = true;
      }
    }
    if(x+1<H){
      if(S[x+1][y]=='.'&&!P[x+1][y]){
        X.push(x+1);Y.push(y);D.push(d+1);
        P[x+1][y] = true;
      }
    }
    if(y-1>=0){
      if(S[x][y-1]=='.'&&!P[x][y-1]){
        X.push(x);Y.push(y-1);D.push(d+1);
        P[x][y-1] = true;
      }
    }
    if(y+1<W){
      if(S[x][y+1]=='.'&&!P[x][y+1]){
        X.push(x);Y.push(y+1);D.push(d+1);
        P[x][y+1] = true;
      }
    }
  }
  if(P[H-1][W-1]){
    cout << H*W - cnt - goalD << endl;
  }else{
    cout << -1 << endl;
  }
}
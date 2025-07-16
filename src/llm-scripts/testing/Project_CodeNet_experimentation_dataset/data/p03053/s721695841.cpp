#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll> ;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI  3.1415926535
#define rep(i, k, n) for(ll i = k; i < n; i++)

vector<vector<char>> maze; //迷路を表す文字列
vvll cnt; //何回目の操作後に黒になったか
ll INF = 10000000000;

ll r, c; 
ll dy[4] = {0, 1, 0, -1};
ll dx[4] = {1, 0, -1, 0};

void bfs(){
  queue<pll> que;
  
  //黒の位置をキューに入れる
  rep(i, 0, r){
    rep(j, 0, c){
      if(maze[i][j] == '#'){que.push(pll(i, j)); cnt[i][j] = 0;}
    }
  }
  
  //キューが空になるまでループ
  while(que.size()){
    //キューの先頭を取り出す
    pll p = que.front();
    que.pop();
    
    //移動四方向ループ
    rep(i, 0, 4){
      //移動後の点(nx,ny)
      ll ny = p.first + dy[i];
      ll nx = p.second + dx[i];
      //移動可能か、すでに訪れているか判定
      if(ny >= 0 && ny < r && nx >= 0 && nx < c && cnt[ny][nx] == INF && maze[ny][nx] != '#'){
        //移動できるならキューに入れ、その点をpの距離＋１にする
        que.push(pll(ny, nx));
        cnt[ny][nx] = cnt[p.first][p.second] + 1;
      }
    }
  }
      
  return;
}
      

int main(){
  cin >> r >> c;
  
  maze = vector<vector<char>> (r,vector<char>(c));
  cnt = vvll (r,vll(c,INF));
  ll ans = 0;
  
  rep(i, 0, r){
    rep(j, 0, c){
      cin >> maze[i][j];
    }
  }
  
  bfs();
  
  rep(i, 0, r){
    rep(j, 0, c){
      if(cnt[i][j] > ans){ans = cnt[i][j];}
    }
  }
  cout << ans << endl;
}





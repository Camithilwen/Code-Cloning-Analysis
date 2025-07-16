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
vvll d; //距離
ll INF = 10000000000;

ll r, c; 
ll dy[4] = {0, 1, 0, -1};
ll dx[4] = {1, 0, -1, 0};

ll bfs(){
  queue<pll> que;
  //全ての点をINFで初期化
  rep(i, 0, r){
    rep(j, 0, c){
      d[i][j] = INF;
    }
  }
  
  //スタート地点をキューに入れ、距離を0にする
  que.push(pll(0, 0));
  d[0][0] = 0;
  
  //キューが空になるまでループ
  while(que.size()){
    //キューの先頭を取り出す
    pll p = que.front();
    que.pop();
    
    //取り出してきたものがゴールなら探索終了
    if(p.first == r-1 && p.second == c-1){break;}
    
    //移動四方向ループ
    rep(i, 0, 4){
      //移動後の点(nx,ny)
      ll ny = p.first + dy[i];
      ll nx = p.second + dx[i];
      //移動可能か、すでに訪れているか判定
      if(ny >= 0 && ny < r && nx >= 0 && nx < c && d[ny][nx] == INF && maze[ny][nx] != '#'){
        //移動できるならキューに入れ、その点をpの距離＋１にする
        que.push(pll(ny, nx));
        d[ny][nx] = d[p.first][p.second] + 1;
      }
    }
  }
      
  return d[r-1][c-1];
}
      

int main(){
  cin >> r >> c;
  
  maze = vector<vector<char>> (r,vector<char>(c));
  d = vvll (r,vll(c,INF));
  ll num_akichi = 0;
  
  rep(i, 0, r){
    rep(j, 0, c){
      cin >> maze[i][j];
      if(maze[i][j] == '.'){num_akichi ++;}
    }
  }
  
  ll dist = bfs();
 
  ll score;
  
  if(dist == INF){score = -1;}
  else{score = num_akichi - dist - 1;}
      
  cout << score << endl;    
      
}





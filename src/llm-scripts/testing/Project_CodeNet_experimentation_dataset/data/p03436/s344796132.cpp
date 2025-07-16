#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0 , -1};

const int INF = 100000;
int main() {
  
  int wcount = 0;
  char grid[100][100];
  int H, W;
  cin >> H >> W;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.') wcount++;
    }
  }
  
  
  int dp[100][100];
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      dp[i][j] = INF;
    }
  }
  
  dp[1][1] = 0;
  
  
  queue<pair<int,int>> que;
  pair<int, int> p = make_pair(1,1);
  que.push(p);
  
  while(que.size()) {
    pair<int, int> p = que.front(); 
    que.pop();
    
    int h = p.first, w = p.second;
    
    for (int i = 0; i < 4; i++) {
      int nh = h + dh[i], nw = w + dw[i];
      
      if (grid[nh][nw] == '.' && dp[nh][nw] == INF && nh >=1 && nh <= H && nw >= 1 && nw <= W) {
        dp[nh][nw] = dp[h][w] + 1;        
        pair<int, int> np = make_pair(nh,nw);
        que.push(np);
      }
    }
  }
  
  if (dp[H][W] == INF) {
    cout << -1 << endl;
  } else {
    cout << wcount - dp[H][W] - 1 << endl;
  }
  
  
  
}
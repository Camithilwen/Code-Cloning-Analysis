// based on http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2784229#1
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <utility>
#include <map>
int needleX[4] = { -1,0,1,0 };
int needleY[4] = { 0,1,0,-1 };
bool dfs(int x, int y, int goalx, int goaly, std::vector<std::vector<bool>>&canGo) {
  if (x == goalx && y == goaly) { return true; }
  canGo[y][x] = false;
  for (int i = 0; i < 4; i++) {
    int next_x = x + needleX[i];
    int next_y = y + needleY[i];
 
    if (canGo[next_y][next_x]) {
      bool flag = dfs(next_x, next_y, goalx, goaly, canGo);
      if (flag)
        return true;
    }
  }
  return false;
}
int main(void) {
  int h, w, n;
  std::cin >> w >> h;
  std::vector<std::string> ans;
  while(!(h == 0 && w == 0)){
    int color=-1, orient, leftX, leftY;
    int sx, sy, gx, gy;
    std::cin >> sx >> sy >> gx >> gy;
    std::vector<std::vector<int>> board(h + 2, std::vector<int>(w + 2, 0));
    std::vector<std::vector<bool>> canGo(h + 2, std::vector<bool>(w + 2, false));
    std::cin >> n;
    int start = -1, goal = -1;
    for (int i = 0; i < n; i++) {
      std::cin >> color >> orient >> leftX >> leftY;
 
 
      if (orient == 0) {
        for (int j = 0; j <= 3; j++) {
          for (int k = 0; k <= 1; k++) {
            board[leftY + k][leftX + j] = color;
            if (leftX + j == sx && leftY + k == sy) {
              start = color;
            }
            else if (leftX + j == gx && leftY + k == gy) {
              goal = color;
            }
          }
        }
 
      }
      else {
        for (int j = 0; j <= 1; j++) {
          for (int k = 0; k <= 3; k++) {
            board[leftY + k][leftX + j] = color;
            if (leftX + j == sx && leftY + k == sy) {
              start = color;
            }
            else if (leftX + j == gx && leftY + k == gy) {
              goal = color;
            }
          }
        }
      }
    }

    // for (int i = 0; i <= h; i++) {
    //   for (int j = 0; j <= w; j++) {
    //     std::cerr << board[i][j] << " ";
    //   }
    //   std::cerr << std::endl;
    // }
    
    if (start != -1) {
      for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
          if (board[i][j] == start) {
            canGo[i][j] = true;
          }
        }
      }
    }

    if (start != goal || start == -1) {
      ans.push_back("NG");
      std::cin >> w >> h;
      continue;
    }

    bool result = dfs(sx, sy, gx, gy, canGo);
    if (result) { ans.push_back("OK"); }
    else { ans.push_back("NG"); }
    std::cin >> w >> h;
  }
  int anssize = ans.size();
  for (int i = 0; i < anssize; i++) {
    std::cout << ans[i] << std::endl;
  }
  return 0;
}


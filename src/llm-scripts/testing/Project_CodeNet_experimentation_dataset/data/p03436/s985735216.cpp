#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  int memo = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> s.at(i).at(j);
      if (s.at(i).at(j) == '.') {
        memo++;
      }
    }
  }
  vector<vector<int>> M(H, vector<int>(W, 0));
  queue<int> X;
  queue<int> Y;
  X.push(0);
  Y.push(0);
  vector<int> vx = {1, -1, 0, 0}, vy = {0, 0, 1, -1};
  s.at(0).at(0) = '#';
  while (X.size() > 0) {
    for (int i = 0; i < 4; i++) {
      if ((X.front() + vx.at(i)) >= 0 && (Y.front() + vy.at(i)) >= 0 
          && (X.front() + vx.at(i)) < H && (Y.front() + vy.at(i)) < W
          && s.at(X.front() + vx.at(i)).at(Y.front() + vy.at(i)) == '.' 
          && M.at(X.front() + vx.at(i)).at(Y.front() + vy.at(i)) == 0) {
            X.push(X.front() + vx.at(i));
            Y.push(Y.front() + vy.at(i));
            M.at(X.front() + vx.at(i)).at(Y.front() + vy.at(i)) = M.at(X.front()).at(Y.front()) + 1;
      }
    }
    X.pop();
    Y.pop();
  }
  if (M.at(H - 1).at(W - 1) != 0) {
    cout << memo - (M.at(H - 1).at(W - 1) + 1) << endl;
  }
  else {
    cout << -1 << endl;
  }
}
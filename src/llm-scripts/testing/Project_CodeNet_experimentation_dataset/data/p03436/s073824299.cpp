#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<char>> maze(51, vector<char>(51));
vector<vector<bool>> check(51, vector<bool>(51));
bool goal;

queue<pair<int, int>> BFS(queue<pair<int, int>> q, pair<int, int> p) {
  int y = p.first, x = p.second;
  //cout << y << " " << x <<endl;
  if (y == H - 1 && x == W - 1) {
    goal = true;
  }
  pair<int, int> tmp;
  //上
  if (y > 0 && maze[y - 1][x] == '.' && !check[y - 1][x]) {
    check[y-1][x] = true;
    tmp = make_pair(y - 1, x);
    q.push(tmp);
  }
  //下
  if (y < H - 1 && maze[y + 1][x] == '.' && !check[y + 1][x]) {
    check[y+1][x] = true;
    tmp = make_pair(y + 1, x);
    q.push(tmp);
  }
  //左
  if (x > 0 && maze[y][x - 1] == '.' && !check[y][x - 1]) {
    check[y][x-1] = true;
    tmp = make_pair(y, x - 1);
    q.push(tmp);
  }
  //右
  if (x < W - 1 && maze[y][x + 1] == '.' && !check[y][x + 1]) {
    check[y][x+1] = true;
    tmp = make_pair(y, x + 1);
    q.push(tmp);
  }
  return q;
}

int clearMaze() {
  queue<pair<int, int>> q, q2;
  pair<int, int> start = make_pair(0, 0);
  q2.push(start);
  check[0][0] = true;
  int i = 0;
  while (true) {
    if(goal){
      return i;
    }
    if(q2.empty()){
      return -1;
    }
    i++;
    q.swap(q2);
    while (!q.empty()) {
      q2 = BFS(q2, q.front());
      q.pop();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> H >> W;
  int white = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> maze[i][j];
      if(maze[i][j] == '.'){
        white++;
      }
    }
  }
  int root = clearMaze();
  if(root > 0){
    cout << white - root <<endl;;
  } else{
    cout << -1 <<endl;
  }
}
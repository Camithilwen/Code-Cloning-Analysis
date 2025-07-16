#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

queue<pair<int, int>> q;
int H, W;
int grid[1005][1005], shortestPath[1005][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool inside(int row, int col){
  if (row < 0 || row >= H || col < 0 || col >= W) return false;
  return true;
}

int bfs(){
  int ans = 0;
  while(!q.empty()){
    pair<int, int> now = q.front();
    q.pop();

    int row = now.first;
    int col = now.second;

    ans = max(ans, shortestPath[row][col]);

    for(int i=0; i<4; i++){
      int nextRow = row + dx[i];
      int nextCol = col + dy[i];

      if(inside(nextRow, nextCol) && grid[nextRow][nextCol] != 1 && shortestPath[nextRow][nextCol] == -1){
        shortestPath[nextRow][nextCol] = 1 + shortestPath[row][col];
        q.push(make_pair(nextRow, nextCol));
      }
    }

  }
  return ans;
}

int main(){
  memset(shortestPath, -1, sizeof(shortestPath));
  cin >> H >> W;

  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      char c;
      cin >> c;
      if(c == '#'){
        grid[i][j] = 1;
        q.push(make_pair(i, j));
        shortestPath[i][j] = 0;
      }
    }
  }

  cout << bfs() << endl;

}
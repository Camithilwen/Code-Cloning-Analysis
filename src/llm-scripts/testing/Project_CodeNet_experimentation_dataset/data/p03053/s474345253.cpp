#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void print_vec(vector<vector<int> > a, int H, int W){
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}

int find_max(vector<vector<int> > a,int H, int W){
  int max = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(max < a.at(i).at(j))
        max = a.at(i).at(j);
    }
  }
  return max;
}


int main(int argc, char *argv[])
{
  int H,W,x,y;
  char tmp;
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  queue<int> queue_x,queue_y;
  cin >> H >> W;
  vector<vector<int> > a(H, vector<int>(W)), visited(H,vector<int>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> tmp;
      if(tmp == '.'){
        a.at(i).at(j) = 0;
        visited.at(i).at(j) = 0;
      }
      else{
        a.at(i).at(j) = 1;
        visited.at(i).at(j) = 1;
        queue_x.push(j);
        queue_y.push(i);
      }
    }
  }
  //print_vec(a,H,W);
  //print_vec(visited,H,W);
  while(!queue_x.empty() && !queue_y.empty()){
    x = queue_x.front();
    y = queue_y.front();
    queue_x.pop();queue_y.pop();
    //cout << "x: " << x << " y: " << y << endl;
    for(int i = 0;i < 4;i++){
      if(0 <= x+dx[i] && x+dx[i] < W && 0 <= y+dy[i] && y+dy[i] < H &&
          a.at(y+dy[i]).at(x+dx[i]) == 0 &&
          visited.at(y+dy[i]).at(x+dx[i]) == 0){
        queue_x.push(x+dx[i]);
        queue_y.push(y+dy[i]);
        visited.at(y+dy[i]).at(x+dx[i]) = visited.at(y).at(x) + 1;
      }
    }
  //print_vec(visited,H,W);
  }
  //print_vec(visited,H,W);
  int ans = find_max(visited,H,W);
  cout << ans-1 << endl;
  return 0;
}

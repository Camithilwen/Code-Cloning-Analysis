#include<iostream>
#include<queue>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  int N = H*W;
  int A[N]; string str;
  int white_num = 0;
  for (int i = 0; i < H; i++) {
    cin >> str;
    for (int j = 0; j < W; j++) {
      white_num += A[i*W+j] = (str[j] == '.');
    }
  }
  queue<pair<int, int>> Q; Q.push(make_pair(0, 1));
  bool visited[N]; for (int i = 0; i < N; i++) visited[i] = false;
  visited[0] = true;
  int score = -1;
  while (!Q.empty()) {
    auto front = Q.front(); Q.pop();
    int u = front.first, d = front.second;
    if (u == H*W-1) { score = white_num-d; break; }
    vector<int> e;
    if (u >= W) e.push_back(u-W);
    if (u % W > 0) e.push_back(u-1);
    if (u % W < W-1) e.push_back(u+1);
    if (u / W < H-1) e.push_back(u+W);
    for (int v : e) {
      if (A[v] && !visited[v]) {
        visited[v] = true;
        Q.push(make_pair(v, d+1));
      }
    }
  }
  cout << score << endl;
}
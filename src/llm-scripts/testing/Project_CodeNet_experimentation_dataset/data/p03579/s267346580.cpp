#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> way;
int64_t N, M;
vector<int> color;

bool dfs(int x, int col) {
  color.at(x) = col;
  for(int i = 0; i < way.at(x).size(); i++) {
    if(color.at(way.at(x).at(i)) == col) {
      return false;
    }
    if(color.at(way.at(x).at(i)) == -1) {
      if(!dfs(way.at(x).at(i), 1 - col)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> N >> M;
  way.assign(N, {});
  color.assign(N, -1);
  for(int64_t i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    way.at(a - 1).push_back(b - 1);
    way.at(b - 1).push_back(a - 1);
  }
  if(!dfs(0, 0)) {
    cout << N * (N - 1) / 2 - M << endl;
  }
  else {
    int64_t total = 0;
    for(int i = 0; i < N; i++) {
      if(color.at(i) == 0) {
        total++;
      }
    }
    cout << total * (N - total) - M << endl;
  }
}
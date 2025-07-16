#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int nowcolor, vector<vector<int>> &way, vector<int> &color) {
  color.at(i) = nowcolor;
  for(int j = 0; j < way.at(i).size(); j++) {
    if(color.at(way.at(i).at(j)) == nowcolor) {
      return false;
    }
    else if(color.at(way.at(i).at(j)) == -1) {
      color.at(way.at(i).at(j)) = 1 - nowcolor;
      if(!dfs(way.at(i).at(j), 1 - nowcolor, way, color)) {
        return false;
      }
    }
  }
  return true;
}
            
int main() {
  int64_t N, M;
  cin >> N >> M;
  vector<vector<int>> way(N);
  for(int64_t i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    way.at(a - 1).push_back(b - 1);
    way.at(b - 1).push_back(a - 1);
  }
  vector<int> color(N, -1);
  if(!dfs(0, 0, way, color)) {
    cout << N * (N - 1) / 2 - M << endl;
  }
  else {
    int count = 0;
    for(int i = 0; i < N; i++) {
      if(color.at(i) == 1) {
        count++;
      }
    }
    cout << count * (N - count) - M << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> a[i][j];
    }
  }
  vector<tuple<int, int, int, int>> op;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W - 1; j++){
      if (a[i][j] % 2 == 1){
        a[i][j]--;
        a[i][j + 1]++;
        op.push_back(make_tuple(i + 1, j + 1, i + 1, j + 2));
      }
    }
  }
  for (int i = 0; i < H - 1; i++){
    if (a[i][W - 1] % 2 == 1){
      a[i][W - 1]--;
      a[i + 1][W - 1]++;
      op.push_back(make_tuple(i + 1, W, i + 2, W));
    }
  }
  int N = op.size();
  cout << N << endl;
  for (int i = 0; i < N; i++){
    cout << get<0>(op[i]) << ' ' << get<1>(op[i]) << ' ' << get<2>(op[i]) << ' ' << get<3>(op[i]) << endl;
  }
}
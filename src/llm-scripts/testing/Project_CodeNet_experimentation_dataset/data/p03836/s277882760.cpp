/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

const int64_t dxs[] = {-1, 1, 0, 0};
const int64_t dys[] = {0, 0, -1, 1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  // 1********
  for (int64_t i = 0; i < (tx - sx); ++i) {
    cout << "R";
  }
  for (int64_t i = 0; i < ty - sy; ++i) {
    cout << "U";
  }
  // 2********
  for (int64_t i = 0; i < (tx - sx); ++i) {
    cout << "L";
  }
  for (int64_t i = 0; i < ty - sy; ++i) {
    cout << "D";
  }
  // 3********
  cout << "D";
  for (int64_t i = 0; i < (tx - sx) + 1; ++i) {
    cout << "R";
  }
  for (int64_t i = 0; i < ty - sy + 1; ++i) {
    cout << "U";
  }
  cout << "L";
  // 4********
  cout << "U";
  for (int64_t i = 0; i < (tx - sx) + 1; ++i) {
    cout << "L";
  }
  for (int64_t i = 0; i < ty - sy + 1; ++i) {
    cout << "D";
  }
  cout << "R";
  cout << endl;

  return 0;
}

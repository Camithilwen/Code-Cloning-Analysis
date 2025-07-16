#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> M(H);
  for (int i = 0; i < H; i++) {
    cin >> M[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (M[i][j] == '#') {
        if ((i + 1 < H && M[i + 1][j] == '#') ||
            (0 <= i - 1 && M[i - 1][j] == '#') ||
            (j + 1 < H && M[i][j + 1] == '#') ||
            (0 <= j - 1 && M[i][j - 1] == '#'))
          continue;
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
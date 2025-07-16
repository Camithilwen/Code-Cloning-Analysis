#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n, v;
  cin >> n;
  vector<vector<int>> V(2, vector<int>(100001));
  for (int i = 0; i != n; ++i) {
    cin >> v;
    ++V[i % 2][v];
  }

  vector<vector<int>> I(2, vector<int>(100001));
  for (auto i : {0, 1}) {
    iota(begin(I[i]), end(I[i]), 1);
    partial_sort(begin(I[i]), begin(I[i]) + 2, end(I[i]),
                 [&](int a, int b) { return V[i][a] > V[i][b]; });
  }
  auto ans = n - ((I[0][0] != I[1][0]) ? V[0][I[0][0]] + V[1][I[1][0]]
                                       : max(V[0][I[0][0]] + V[1][I[1][1]],
                                             V[0][I[0][1]] + V[1][I[1][0]]));
  cout << ans << endl;
}

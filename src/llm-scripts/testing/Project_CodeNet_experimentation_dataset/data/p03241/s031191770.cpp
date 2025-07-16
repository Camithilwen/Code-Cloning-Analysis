#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N, M;
  cin >> N >> M;
  int64_t res = 1;
  for (int64_t m = 1; m <= sqrt(M); ++m) {
    if (M % m) continue;
    int64_t m2 = M / m;
    if (m >= N) res = max(res, m2);
    if (m2 >= N) res = max(res, m);
  }
  cout << res << endl;
  
  return 0;
}

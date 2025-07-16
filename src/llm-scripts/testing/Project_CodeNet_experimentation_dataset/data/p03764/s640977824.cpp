// you can use includes, for example:
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <set>
#include <cassert>
#include <map>

using namespace std;

constexpr int64_t kMod = 1e9 + 7;

int main(void) {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  auto calc = [](int n) {
    int64_t cur_x = 0;
    int64_t cur_sum_x = 0;
    for (int i = 0; i < n; i++) {
      int64_t x;
      cin >> x;
      if (i) {
        cur_sum_x += x * (i) - cur_x;
      }
      cur_x += x;
      cur_x %= kMod;
      cur_sum_x %= kMod;
    }
    return (cur_sum_x + kMod) % kMod;
  };

  auto x_sum = calc(n);
  auto y_sum = calc(m);
  cout << x_sum * y_sum % kMod << endl;
}

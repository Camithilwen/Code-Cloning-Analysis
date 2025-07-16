#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;
  vector<int64_t> parts_a(N);
  for (int64_t n = 0; n < N; ++n) {
    cin >> parts_a[n];
  }
  sort(parts_a.begin(), parts_a.end());
  
  vector<int64_t> parts_b(N);
  for (int64_t n = 0; n < N; ++n) {
    cin >> parts_b[n];
  }
  
  vector<int64_t> parts_c(N);
  for (int64_t n = 0; n < N; ++n) {
    cin >> parts_c[n];
  }
  sort(parts_c.begin(), parts_c.end());
  
  int64_t result = 0;
  for (int64_t n = 0; n < N; ++n) {
    auto it = lower_bound(parts_a.begin(), parts_a.end(), parts_b[n]);
    int64_t a_num = (it - parts_a.begin());
    auto it2 = upper_bound(parts_c.begin(), parts_c.end(), parts_b[n]);
    int64_t b_num = (parts_c.end() - it2);
    result += a_num * b_num;
  }
  cout << result << endl;
  
  return 0;
}

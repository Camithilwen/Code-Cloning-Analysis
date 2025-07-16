#include <iostream>
#include <algorithm>

int main() {
  long long n, t;
  std::cin >> n >> t;
  long long timings[n], intervals[n - 1];
  for (long long i = 0; i < n; i++) {
    std::cin >> timings[i];
    if (i > 0) {
      intervals[i - 1] = timings[i] - timings[i - 1];
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n - 1; i++) {
    ans += std::min(intervals[i], t);
  }
  ans += t;
  std::cout << ans << "\n";
  return 0;
}
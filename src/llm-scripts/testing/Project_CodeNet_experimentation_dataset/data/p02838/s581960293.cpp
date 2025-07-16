#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

constexpr int64_t MOD = 1e9+7;

int main() {
  int N;
  cin >> N;

  vector<int64_t> nums(N);
  for (int n = 0; n < N; ++n) {
    cin >> nums[n];
  }
  sort(nums.begin(), nums.end());
  
  vector<vector<int64_t>> cnt(2, vector<int64_t>(61));                              
  for (int64_t n : nums) {
    bitset<61> bs(n);
    for (size_t i = 0; i <= 60; ++i) {
      if (bs.test(i)) {
        ++cnt[1][i];
      } else {
        ++cnt[0][i];
      }
    }
  }
  int64_t result = 0;
  for (size_t i = 0; i <= 60; ++i) {
    result += (static_cast<int64_t>(pow(2, i)) % MOD) * (cnt[0][i] * cnt[1][i] % MOD);
    result %= MOD;
  }
  cout << result << endl;
  
  return 0;
}
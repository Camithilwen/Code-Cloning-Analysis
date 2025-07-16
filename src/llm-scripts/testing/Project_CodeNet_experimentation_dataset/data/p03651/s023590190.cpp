/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int64_t GreatestCommonDivisor(const int64_t a, const int64_t b) {
  // GCD. O(log(min(a, b))). 最大公約数.
  int64_t result = -1LL;
  if (a < 0) {
    std::cerr << "ERROR: GreatestCommonDivisor(): a is out of range: " << a << std::endl;
    throw 1;
  } else if (b < 0LL) {
    std::cerr << "ERROR: GreatestCommonDivisor(): b is out of range: " << b << std::endl;
    throw 1;
  } else if (a == 0LL) {
    result = b;
  } else if (b == 0LL) {
    result = a;
  } else {
    const int64_t new_a = std::min(a, b);
    const int64_t new_b = std::max(a, b) % new_a;  // Euclidean Algorithm
    result = GreatestCommonDivisor(new_a, new_b);
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, K;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
  }
  int64_t temp = A[0];
  for (int64_t i = 1; i < N; ++i) {
    temp = GreatestCommonDivisor(temp, A[i]);
  }
  if (K % temp == 0 && K <= (*max_element(A.begin(), A.end()))) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}

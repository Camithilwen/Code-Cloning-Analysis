#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

bool is_prime(int n) {
  for (int p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      return false;
    }
  }

  return true;
}

vector<pair<int, int>> factorize(int n) {
  vector<pair<int, int>> result;
  for (int p = 2; p * p <= n; p++) {
    if (is_prime(p)) {
      int cnt = 0;
      while (n % p == 0) {
        n /= p;
        cnt++;
      }
      if (cnt > 0) {
        result.push_back(make_pair(p, cnt));
      }
    }
  }
  if (n != 1) {
    result.push_back(make_pair(n, 1));
  }
  return move(result);
}

int main() {
  int n;
  cin >> n;
  vector<int> e(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    auto factor = factorize(i);
    for (const auto f : factor) {
      int p, j;
      tie(p, j) = f;
      e[p] += j;
    }
  }

  const int64_t MOD = 1e9 + 7;
  int64_t result = 1;
  for (int i = 1; i <= n; i++) {
    result *= e[i] + 1;
    result %= MOD;
  }
  cout << result << endl;

  return 0;
}
#include <iostream>

using namespace std;

const int MOD = 1000000007;

int dv[1000];

int sqrt(int x) {
  int l = 1, r = x;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    (m * m <= x ? l : r) = m;
  }
  return l;
}

void memoDivisor(int n) {
  while (n > 1) {
    for (int i = 2; i <= n; ++i) {
      if (n % i == 0) {
        dv[i]++;
        n /= i;
        break;
      }
    }
  }
}

int main() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i) memoDivisor(i);

  long long cnt = 1;
  for (int i = 2; i <= N; ++i) {
    cnt = cnt * (dv[i] + 1) % MOD;
  }

  cout << cnt << endl;
}

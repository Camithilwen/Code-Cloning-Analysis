#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int A, B, M;
  std::cin >> A >> B >> M;
  std::vector<int> a(A), b(B), x(M), y(M), c(M);
  rep(i, A) std::cin >> a[i];
  rep(i, B) std::cin >> b[i];
  rep(i, M) {
    std::cin >> x[i] >> y[i] >> c[i];
  }

  int minv = 1000000;
  rep(i, M) {
    minv = min(minv, a[x[i]-1] + b[y[i]-1] - c[i]);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  minv = min(minv, a[0] + b[0]);

  std::cout << minv << std::endl;

  return 0;
}

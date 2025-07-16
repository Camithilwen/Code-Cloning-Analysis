#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll N, A, ans{}, s{}, m{1 << 30};
  cin >> N;
  for (int i = 0; i != N; ++i) {
    cin >> A;
    if (A < 0) A *= -1, ++s;
    m = min(m, A);
    ans += A;
  }
  cout << ans - (s % 2 ? 2 * m : 0) << endl;
}

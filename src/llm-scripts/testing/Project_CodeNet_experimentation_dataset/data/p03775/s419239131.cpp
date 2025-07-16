#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N;
  cin >> N;
  ll sqrN = sqrt(N);
  for (ll i = sqrN; i >= 1; i--) {
    if (N % i == 0) {
      ll a = N / i;
      string sa = to_string(a);
      cout << sa.size() << endl;
      return 0;
    }
  }
}

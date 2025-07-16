#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  for (int i = N; i > 0; i--) {
    double a = sqrt(i);
    if (ceil(a) == floor(a)) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}

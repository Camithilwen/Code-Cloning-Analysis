#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, R;
  cin >> N >> R;
  if (N < 10) {
    R += 100 * (10 - N);
  }
  cout << R << '\n';
  return 0;
}
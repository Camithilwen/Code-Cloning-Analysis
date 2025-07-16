#include <bits/stdc++.h>
#define sz(arr) (int)(arr).size()
#define rng(arr) arr.begin(), arr.end()
#define show(x) cout << #x << " = " << x << endl;

using namespace std;
typedef long long int ll;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

#define Cins(T, n, xs) \
  vector<T> xs(n);     \
  for (int i = 0; i < n; ++i) cin >> xs[i]

void Main();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  Main();
  return 0;
}

void Main() {
  Cin(int, n);
  Cins(int, n, a);

  int sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];

  double mean = (double)sum / n;

  double mi = 1001001001;
  int mii = -1;
  for (int i = 0; i < n; ++i) {
    double sa = abs(a[i] - mean);
    if (mi > sa) {
      mi = sa;
      mii = i;
    }
  }

  cout << mii << endl;
}
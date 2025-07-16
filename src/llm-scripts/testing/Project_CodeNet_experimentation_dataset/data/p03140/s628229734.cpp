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
  Cin(string, a, b, c);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    map<char, int> mp;
    mp[a[i]]++;
    mp[b[i]]++;
    mp[c[i]]++;

    int ma = 0;
    for (auto e : mp) ma = max(ma, e.second);
    ans += 3 - ma;
  }

  cout << ans << endl;
}
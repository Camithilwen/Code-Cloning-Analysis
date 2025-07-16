#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll K, T;
  cin >> K >> T;
  vector<ll> a(T);
  for (int i = 0; i < T; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  for (int i = 0; i < T; i++) {
    if (a[i] <= 1) continue;
    ll j = i + 1;
    while (a[i] > 0 && j < T) {
      if (a[j] < 1) {
        j++;
      } else {
        a[i]--;
        a[j]--;
      }
    }
  }
  ll ans = 0;
  for (auto res : a) {
    ans += max(0LL, res - 1);
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int K,T;
  cin >> K >> T;
  int a[T];
  for (int i = 0; i < T; i++) {
    cin >> a[i];
  }
  sort(a,a+T);
  reverse(a,a+T);
  int ma = max(0,a[0] - (K - a[0]));
  int ans = max(0,ma-1);
  cout << ans << endl;
  return 0;
}
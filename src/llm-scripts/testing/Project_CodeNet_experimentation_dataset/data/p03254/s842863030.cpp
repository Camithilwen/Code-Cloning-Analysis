#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int N, x;
  cin >> N >> x;
  int a[N];
  rep(i, N) cin >> a[i];
  sort(a, a+N);

  int ans = 0;

  for (int i = 0; i < N; i++) {
    if (x >= a[i]) {
      ++ans;
      x -= a[i];
    }
  }

  if (ans == N && x > 0) --ans;

  cout << ans << endl;

  return 0;
}
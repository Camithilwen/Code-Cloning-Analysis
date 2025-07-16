#include <bits/stdc++.h>

using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void milktea() {
  int d, g;
  cin >> d >> g;
  vector<int> p(d), c(d);
  for(int i = 0; i < d; i++) {
    cin >> p[i] >> c[i];
  }
  
  int ans = 1e9;
  for(int bit = 0; bit < (1 << d); bit++) {
    int s = 0, num = 0, m = -1;
    for(int i = 0; i < d; i++) {
      if(bit & 1 << i) {
        s += 100 * (i+1) * p[i] + c[i];
        num += p[i];
      } else {
        m = i;
      }
    }
    cout << '\n';
    if(s < g) {
      int s1 = 100 * (m+1);
      int need = (g - s + s1 - 1) / s1;
      if(need >= p[m]) continue;
      num += need;
    }
    ans = min(ans, num);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> tt;
  while(tt--) milktea();

  return 0;
}

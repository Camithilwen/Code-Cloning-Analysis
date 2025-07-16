#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, q;
  string s;
  cin >> n >> s >> q;

  while (q--) {
    int k;
    cin >> k;

    ll ans = 0, a = 0, b = 0, m = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == 'D') a++;
      else if (s[i] == 'M') {
        m++;
        b += a;
      } else if (s[i] == 'C') ans += b;
    }

    for (int i = 1; i <= n - k; i++) {
      if (s[i - 1] == 'D') {
        a--;
        b -= m;
      } else if (s[i - 1] == 'M') m--;

      if (s[i + k - 1] == 'D') a++;
      else if (s[i + k - 1] == 'M') {
        m++;
        b += a;
      } else if (s[i + k - 1] == 'C') ans += b;
    }

    cout << ans << '\n';
  }
}

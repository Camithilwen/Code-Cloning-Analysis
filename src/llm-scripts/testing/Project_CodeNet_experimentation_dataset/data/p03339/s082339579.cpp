#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  string s;
  cin >> n >> s;

  vector<ll> c(n + 1, 0);

  for (ll i = 0; i < n; i++)
  {
    c[i + 1] = c[i];
    if (s[i] == 'W')
    {
      c[i + 1]++;
    }
  }

  ll ans = n;
  for (ll i = 1; i < n + 1; i++)
  {
    ans = min(ans, c[i - 1] + (n - i) - (c[n] - c[i]));
  }
  cout << ans << endl;
}

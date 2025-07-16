#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<int> a(n, 0);
  vector<ll> ans(n, 0);
  ll fee = 0;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  ll tmp = 0;
  for (ll i = 0; i < n + 1; i++)
  {
    if (i == n)
    {
      fee += abs(tmp - 0);
      break;
    }

    fee += abs(tmp - a[i]);
    tmp = a[i];
  }

  for (ll i = 0; i < n; i++)
  {
    ans[i] = fee - (abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i])) + (abs(a[i + 1] - a[i - 1]));
  }

  for (ll i = 0; i < n; i++)
  {
    cout << ans[i] << endl;
  }
}

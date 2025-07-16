#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()

using namespace std;
using ll = long long;

const double PI = 3.14159265358979;

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  vector<ll> na(n, 0);
  vector<ll> nb(n, 0);
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];
  for(int i = 0; i < n; ++i) cin >> c[i];

  sort(ALL(b));
  sort(ALL(c));

  for(int i = 0; i < n; ++i)
  {
    auto itc = upper_bound(ALL(c), b[i]);
    nb[i] = distance(itc, c.end());
  }
  for(int i = n - 2; i >= 0; --i)
  {
    nb[i] += nb[i + 1];
  }
  for(int i = 0; i < n; ++i)
  {
    auto itb = upper_bound(ALL(b), a[i]);
    na[i] = nb[distance(b.begin(), itb)];
  }
  cout << accumulate(ALL(na), 0LL);
}

int main()
{
  fastio;
  solve();

  return 0;
}
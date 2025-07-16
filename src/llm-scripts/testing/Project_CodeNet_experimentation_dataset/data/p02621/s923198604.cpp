#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair <int, int>;

#define rep(i, n)     for (int i = 0; i < (int) (n); i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
#define each(i, mp)   for (auto &i : mp)

const int INF = 1001001001;

int main()
{
  int a;
  cin >> a;
  ll ans = 0;

  rep(i, 3) ans += pow(a, i + 1);
  cout << ans << endl;

  return 0;
}

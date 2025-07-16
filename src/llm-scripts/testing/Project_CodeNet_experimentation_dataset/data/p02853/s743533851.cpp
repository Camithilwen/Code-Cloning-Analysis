#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int X, Y;
  cin >> X >> Y;
  int money[] = {300000,
                 200000,
                 100000};
  int ans = 0;
  if (X < 4)
    ans += money[X - 1];

  if (Y < 4)
    ans += money[Y - 1];

  if (X == 1 && Y == 1)
    ans += 400000;
  cout << ans << endl;
  return 0;
}
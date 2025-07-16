
#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;
using lld = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b)
{
  if (a < b)
  {
    return gcd(b, a);
  }
  while (b != 0)
  {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int main() {
  ll N;
  cin >> N;

  ll mn;
  cin >> mn;
  loop(0, 4, i) {
    ll tmp;
    cin >> tmp;
    mn = min(mn, tmp);
  }

  ll bn;
  if (N % mn == 0) {
    bn = N/mn;
  } else {
    bn = N/mn + 1;
  }

  print(bn + 5 - 1);
}
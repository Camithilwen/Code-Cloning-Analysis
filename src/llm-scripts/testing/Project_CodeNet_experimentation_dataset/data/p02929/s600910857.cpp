/*
ID: skipian1
PROB: 
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF = 2000000000
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define X first
#define Y second

ll MOD = 1e9+7;

int main() {
  ll n;
  cin >> n;
  string str;
  cin >> str;
  bool paren[2*n];
  for (ll i = 0; i < 2*n; i++) {
    if (i == 0) {
      if (str.at(i) == 'W') {
	cout << 0 << "\n";
	return 0;
      }
      paren[0] = 0;
    } else {
      if (str.at(i) != str.at(i-1)) {
	paren[i] = paren[i-1];
      } else {
	paren[i] = !paren[i-1];
      }
    }
  }
  ll parens = 0;
  for (ll i = 0; i < 2*n; i++) {
    if (paren[i]) parens--;
    else parens++;
    if (parens < 0) {
      cout << 0 << "\n";
      return 0;
    }
  }
  if (parens != 0) {
    cout << 0 <<  "\n";
    return 0;
  }
  parens = 0;
  ll ans = 1;
  ll ind = 0;  
  for (ll i = 2*n-1; i >= 0; i--) {
    if (paren[i]) parens++;
    else {
      ans *= parens-ind;
      ind++;
      ans %= MOD;
    }
  }
  for (ll i = 1; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  cout << ans << "\n";
}

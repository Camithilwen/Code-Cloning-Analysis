#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


const ll MAX_N = 1000000010;

int main(void) {
  ll n;
  cin >> n;

  vector<ll> v;
  ll num = 1;
  while (num * num < MAX_N) {
    v.push_back(num * num);
    num++;
  }

  reverse(v.begin(), v.end());

  for (auto sq : v) {
    if (sq <= n) {
      cout << sq << endl;
      return 0;
    }
  }
  
  return 0;
}
#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  ll ans = -INF;

  for (ll i = N; i <= 999; i++) {
    string s = to_string(i);
    if (s[0] == s[1] && s[1] == s[2]) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}

// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation, std::lower_bound
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath> // std::atan2
#include <deque>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> V(N);
  rep (i, N) cin >> V[i];

  deque<ll> treasures;
  rep (i, N) treasures.push_back(V[i]);
  ll ans = numeric_limits<ll>::min();
  for (ll numpop = min(N, K); numpop >= 0; numpop--) {
    ll numpush = K - numpop;
    for (ll numpopL = 0; numpopL < numpop + 1; numpopL++) {
      ll numpopR = numpop - numpopL;
      vector<ll> mytreasures;
      rep (i, numpopL) {
        mytreasures.push_back(treasures.at(i));
        // cerr <<"L"<< mytreasures.back() << endl;
      }
      rep (i, numpopR) {
        mytreasures.push_back(treasures.at(N - i - 1));
        // cerr <<"R"<< mytreasures.back() << endl;
      }
      ll sum = 0;
      for (const auto mytreasure : mytreasures) {
        sum += mytreasure;
      }
      sort(mytreasures.begin(), mytreasures.end());
      for (ll i = 0; i < mytreasures.size() && i < numpush && mytreasures.at(i) < 0;
             ++i) {
        sum -= mytreasures.at(i);
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    p[i] = {a, b};
  }
  sort(p.begin(), p.end(), [](pair<ll, ll> p1, pair<ll, ll> p2) {
      return p1.first + p1.second > p2.first + p2.second;
      });
  ll result = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      result += p[i].first;
    } else {
      result -= p[i].second;
    }
  }
  cout << result << endl;

  return 0;
}

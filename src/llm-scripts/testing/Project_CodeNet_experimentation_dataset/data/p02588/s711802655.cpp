#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>
#include <iomanip>

using ll = long long;
using ld = long double;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
std::vector<std::pair<int,int>> v;
std::map<std::pair<int,int>,int> mp;

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    ld init;
    std::cin >> init;
    ll number = llround(1000000000LL * init);
    std::pair<int,int> basic(0, 0);

    while(number % 2 == 0) {
      number /= 2;
      basic.first++;
    }
    while(number % 5 == 0) {
      number /= 5;
      basic.second++;
    }
    mp[basic]++;
    if(mp[basic] == 1)
      v.push_back(basic);
  }
  ll result = 0;

  for(int i = 0; i < v.size(); i++)
    for(int j = i; j < v.size(); j++)
      if(18 <= v[i].first + v[j].first && 18 <= v[i].second + v[j].second) {
        if(i == j)
          result += 1LL *  mp[v[i]] * (mp[v[i]] - 1) / 2;
        else
          result += 1LL * mp[v[i]] * mp[v[j]];
      }
  std::cout << result;
}

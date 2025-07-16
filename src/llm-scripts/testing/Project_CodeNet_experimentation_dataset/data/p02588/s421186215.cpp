#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main() {
  int n; cin >> n;
  map<pair<int, int>, int> mp;
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    double num; cin >> num;
    long long x = llround(num*1e9);

    int two = 0, five = 0;
    while(x % 2 == 0) two++, x /= 2;
    while(x % 5 == 0) five++, x /= 5;
    for(auto p: mp) {
      if(p.first.first+two >= 18 && p.first.second+five >= 18) ans += p.second;
    }
    mp[make_pair(two, five)]++;
  }
  cout << ans << endl;
  return 0;
}

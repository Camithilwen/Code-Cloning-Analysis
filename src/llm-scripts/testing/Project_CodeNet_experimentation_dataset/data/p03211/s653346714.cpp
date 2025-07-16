#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end()
int main() {
  ll a;
  cin >> a;
  ll ans = 999;
  while(a>99){
    ans = min(ans,abs(753-a%1000));
    a /= 10;
  }
  cout << ans;
} 

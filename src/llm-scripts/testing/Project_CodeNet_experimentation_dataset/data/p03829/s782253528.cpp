#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> x(n);
  rep(i,n) cin >> x[i];

  ll ans = 0;
  rep(i,n-1) ans += min((x[i+1]-x[i])*a,b);
  cout << ans << endl;
}
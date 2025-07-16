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
  ll x;
  cin >> x;
  ll ans = x/11*2;
  if(x%11>0) ++ans;
  if(x%11>6) ++ans;
  cout << ans << endl;
}

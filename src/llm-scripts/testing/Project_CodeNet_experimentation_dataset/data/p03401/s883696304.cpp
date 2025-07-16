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
  int n;
  cin >> n;
  vector<int> a(n+2);
  rep(i,n) cin >> a[i+1];

  vector<int> d(n+1), d2(n);
  int v = 0;
  rep(i,n+1) v += d[i] = abs(a[i]-a[i+1]);
  rep(i,n) d2[i] = abs(a[i]-a[i+2]);

  rep(i,n) cout << v-d[i]-d[i+1]+d2[i] << endl;
}

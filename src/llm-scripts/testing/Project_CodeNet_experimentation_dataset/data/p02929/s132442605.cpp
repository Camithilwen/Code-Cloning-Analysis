#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MOD = 1e9+7;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int lnum = 0;
  ll ans = 1;
  rep(i, n*2) {
    if (s[i]=='B' ^ lnum%2)
      lnum++; //保留にする(=区間の左端として使う)
    else {
      (ans *= lnum) %= MOD;
      lnum--; //保留を一つ消費した
    }
  }
  if (lnum)
    cout << 0 << endl;
  else {
    for (int i=1; i<=n; i++)
      (ans *= i) %= MOD;
    cout << ans << endl;
  }
  return 0;
}
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S; cin >> S;
  int ans = 1000;
  rep(i,S.size()-2) {
    int t = int(S[i]-48) * 100 + int(S[i+1]-48) * 10 + int(S[i+2]-48);
    ans = min(ans, abs(t - 753));
  }
  cout << ans << endl;
  return 0;
}
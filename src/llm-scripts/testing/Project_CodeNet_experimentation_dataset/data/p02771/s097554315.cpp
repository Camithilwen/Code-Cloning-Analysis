#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  vector<int> x(3);
  rep(i, 3) cin >> x.at(i);
  int cnt = 0;
  rep(i, 3) rep(j, 3) {
    if(i == j) continue;
    else if(x.at(i) == x.at(j)) cnt++;
  }
  if(cnt == 2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
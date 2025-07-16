#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> p(m);
  for(int i=0;i<m;i++) cin >> p[i].first >> p[i].second;
  for(int x=0;x<1000;x++) {
    int keta = 1;
    int nx = x/10;
    vector<int> d(1,x%10);
    while (nx) {
      keta++;
      d.push_back(nx%10);
      nx /= 10;
    }
    if (keta != n) continue;
    bool ok = true;
    reverse(d.begin(), d.end());
    for(int i=0;i<m;i++) {
      if (d[p[i].first-1] != p[i].second) ok = false;
    }
    if (ok) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}

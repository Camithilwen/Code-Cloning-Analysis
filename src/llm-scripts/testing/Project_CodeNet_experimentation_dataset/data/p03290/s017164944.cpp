#include <bits/stdc++.h>
using namespace std;

int main () {
  int d, g;
  cin >> d >> g;
  vector<pair<int,int>> p(d);
  for (int i = 0; i < d; i++)
    cin >> p[i].first >> p[i].second;
  
  vector<int> v(d);
  iota (v.begin(), v.end(), 0);
  int ans = 1000;
  do {
    int sum = 0, c = 0;
    for (int i = 0; i < d; i++) {
      int x = v[i];
      int i100 = 100 * (x+1);
      int pi100 = p[x].first * i100;
      if (g > sum + pi100 + p[x].second) {
        sum += pi100 + p[x].second;
        c += p[x].first;
      }
      else if (sum + pi100 <= g &&
               g <= sum + pi100 + p[x].second) {
        c += p[x].first;
        break;
      }
      else {
        c += (g - sum + i100-1) / i100;
        break;
      }
    }
    ans = min(ans, c);
  }
  while (next_permutation(v.begin(), v.end()));
  
  cout << ans << endl;
}

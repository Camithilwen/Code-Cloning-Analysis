#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<long long> a(n);
  const int b = 200;
  for(int i = 0; i < n; i++) {
    double p;
    cin >> p;
    a[i] = p * 1000000000 + 0.5;
  }
  vector<vector<int>> cnt(b, vector<int>(b));
  long long res = 0;
  for(int i = 0; i < n; i++) {
    int two = 0, five = 0;
    while(a[i] % 2 == 0) {
      two++;
      a[i] /= 2;
    }
    while(a[i] % 5 == 0) {
      five++;
      a[i] /= 5;
    }
    res += cnt[18 + b / 2 - two][18 + b / 2 - five];
    for(int u = -30; u <= two; u++) {
      for(int v = -30; v <= five; v++) {
        cnt[b / 2 + u][b / 2 + v]++;
      }
    }
  }
  cout << res;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n+2);
  a[0] = 0;
  a[n+1] = 0;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += abs(a[i] - a[i-1]);
  }
  sum += abs(a[n+1] - a[n]);
  for (int i = 1; i <= n; i++) {
    int diff = abs(a[i+1] - a[i]) + abs(a[i] - a[i-1]) - abs(a[i+1] - a[i-1]);
    cout << sum - diff << endl;
  }
  return 0;
}
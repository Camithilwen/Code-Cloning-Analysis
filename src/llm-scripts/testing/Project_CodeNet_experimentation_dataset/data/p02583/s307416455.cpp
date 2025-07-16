#include<bits/stdc++.h>
using namespace std; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  int ans = 0;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  for (int i = 0 ; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (a[i] == a[j] || a[i] == a[k] || a[j] == a[k]) continue;
        if (a[i] + a[j] > a[k]) {
          ans++;
          //cout << a[i] << " " << a[j] << " " << a[k] << "\n";
        }
      }
    }
  }
  cout << ans << "\n";
}
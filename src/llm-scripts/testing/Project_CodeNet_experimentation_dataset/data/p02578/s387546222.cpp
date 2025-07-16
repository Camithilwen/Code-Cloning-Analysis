#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int64_t ans = 0;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(i>=1) {
      ans += max(0, a[i-1]-a[i]);
      if(a[i-1]-a[i]>0) a[i] = a[i-1];
    }
  } 
  
  cout << ans << endl;
  return 0;
}
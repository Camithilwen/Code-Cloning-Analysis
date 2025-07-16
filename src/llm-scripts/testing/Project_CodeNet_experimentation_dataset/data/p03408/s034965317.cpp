#include<bits/stdc++.h>
#define ll long long
#define INF 100000000000000000LL
using namespace std;
signed main() {
  int n, m, cun, ans = 0;
  string s[10000], t[10000];
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t[i];   
  } 
  
  for (int i = 0; i < n; i++) {
    cun = 0;
    for (int j = 0; j < n; j++) {
      if (s[i] == s[j]) {
        cun++;
      }
    }
    
    for (int j = 0; j <m; j++) {
      if (s[i] == t[j]) {
        cun--;
      }
    }
    ans = max(ans, cun);
  }
  
  cout << ans << "\n";
  return (0);
}
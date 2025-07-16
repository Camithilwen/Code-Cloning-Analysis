#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int MAX = -1;
  int ans = MAX;
  for(int i = 1; i*i <= n; i++) {
    ans = max(ans, i*i);
  }
  
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = 1001001001;
  rep(i,n) {
    int cnt = 0;
    while(a[i] % 2 == 0) {
      a[i] /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
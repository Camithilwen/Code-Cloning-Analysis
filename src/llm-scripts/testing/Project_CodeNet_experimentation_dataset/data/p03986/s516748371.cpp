#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(rng(s));
  bool ok = false;
  int cnt = 0, nt = 0;
  rep(i,n) {
    if(s[i]=='T') nt++;
    if(!ok&&s[i]=='T') ok = true;
    else if(ok&&s[i]=='S'&&nt>0) {
      cnt++;
      nt--;
    }
  }
  int ans = n-cnt*2;
  if(ans<0) ans = 0;
  cout << ans << endl;
  return 0;
}
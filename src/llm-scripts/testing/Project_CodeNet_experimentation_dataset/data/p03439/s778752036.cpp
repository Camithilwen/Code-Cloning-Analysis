#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  auto bsearch = [&]() {
    bool fin = false;
    string s0;

    auto query = [&](int k) {
      cout << k << endl;
      string s;
      cin >> s;
      return s;
    };
    auto test = [&](int k) {
      string s = query(k);
      if(s == "Vacant") {
        return fin = true;
      } else if((k%2==1 && s!=s0) || (k%2==0 && s==s0)) {
        return true;
      } else {
        return false;
      }
    };

    int ok = 0, ng = N;
    s0 = query(0);
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      if(test(mid)) {
        if(fin) return;
        ok = mid;
      } else {
        ng = mid;
      }
    }
  };
  bsearch();
  return 0;
}

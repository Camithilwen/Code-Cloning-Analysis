#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; cin >> n >> m;
  vector<int> p(n+1,0);
  vector<bool> ac(n+1);
  int ac_cnt = 0, pe_cnt = 0;
  rep(i,m) {
    int pi; string si; cin >> pi >> si;
    if (!ac[pi]) {
      if (si == "WA") {
        p[pi]++;
      } else {
        ac_cnt++;
        pe_cnt += p[pi];
        ac[pi] = true;
      }
    }
  }
  cout << ac_cnt << " " << pe_cnt << endl;
  return 0;
}
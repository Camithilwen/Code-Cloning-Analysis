#include<bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int N;
  cin >> N;
  vpr L, R;
  vector<string> vec(N);
  rep(i, N) {
    string s;
    cin >> s;
    vec[i] = s;
    int sz = s.size();
    int maxl = 0, maxr = 0, l = 0, r = 0;
    rep(j, sz) {
      if(s[j] == ')') l++;
      else l--;
      chmax(maxl, l);
      if(s[sz-j-1] == '(') r++;
      else r--;
      chmax(maxr, r);
    }
    if(maxl <= maxr) L.push_back(make_pair(maxl, i));
    else R.push_back(make_pair(maxr, i));
  }
  sort(ALL(L), less<pair<ll, ll>>());
  sort(ALL(R), greater<pair<ll, ll>>());
  copy(ALL(R), back_inserter(L));
  int cnt = 0;
  for(auto& l : L) {
    int sz = vec[l.second].size();
    rep(j, sz) {
      if(vec[l.second][j] == '(') cnt++;
      else cnt--;
      if(cnt < 0) {
        cout << "No\n";
        return;
      }
    }
  }
  if(cnt == 0) cout << "Yes\n";
  else cout << "No\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
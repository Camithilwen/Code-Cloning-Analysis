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
  int n; cin >> n;
  vector<string> S(n);
  vector<vector<pair<int, int>>> v(4);
  int sum = 0;
  rep(i, n) {
    cin >> S[i];
    int cnt=0, mn=0;
    for(char c: S[i]) {
      cnt += (c=='(' ? 1 : -1);
      mn = min(cnt, mn);
    }
    sum += cnt;
    if(mn == 0 && cnt >= 0) {
      v[0].push_back({mn, cnt});
    } else if(mn < 0 && cnt >= 0) {
      v[1].push_back({mn, cnt});
    } else if(mn == cnt && cnt <= 0) {
      v[2].push_back({mn, cnt});
    } else {
      v[3].push_back({mn, cnt});
    }
  }
  auto no = [&]() {
    cout << "No" << "\n";
    exit(0);
  };
  if(sum != 0) no();
  sum = 0;
  for(auto p: v[0]) {
    sum += p.second;
  }
  sort(all(v[1]), greater<pair<int, int>>());
  for(auto p: v[1]) {
    if(sum + p.first < 0) no();
    sum += p.second;
  }
  sum = 0;
  for(auto p: v[2]) {
    sum += -p.second;
  }
  sort(all(v[3]), [&](pair<int, int> p1, pair<int, int> p2) {
      if(p1.first == p2.first) {
        return p1.second < p2.second;
      }
      return p1.first-p1.second > p2.first-p2.second;
    });
  for(auto p: v[3]) {
    if(sum + p.first-p.second < 0) no();
    sum += -p.second;
  }
  cout << "Yes" << "\n";
  return 0;
}

#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  priority_queue<pair<int, int>> pq;
  int k,t; cin >> k >> t;
  rep(i, t) {
    int a; cin >> a;
    pq.push(make_pair(a, i));
  }

  int ans = 0;
  int beforeT = -1;
  while(!pq.empty()) {
    auto top = pq.top(); pq.pop();

    if(beforeT == top.second) {
      if(pq.size() == 0) {
        ++ans;
        --top.first;
        if(top.first == 0) {
          break;
        } else {
          pq.push(top);
          continue;
        }
      }

      auto prev = pq.top(); pq.pop();
      --prev.first;
      beforeT = prev.second;
      if(prev.first > 0) {
        pq.push(prev);
      }
      pq.push(top);
      continue;
    }

    beforeT = top.second;
    --top.first;
    if(top.first != 0) {
      pq.push(top);
    }
  }

  std::cout << ans << endl;
  return 0;
}

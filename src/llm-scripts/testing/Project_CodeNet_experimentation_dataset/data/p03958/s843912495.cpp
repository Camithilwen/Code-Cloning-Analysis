#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int k, t;
  cin >> k >> t;
  int ans = 0;
  int prev = -1;
  priority_queue<pair<int, int>> data;
  REP(i, t) {
    int x;
    cin >> x;
    pair<int, int> p = make_pair(x, i + 1);
    data.push(p);
  }

  while (!data.empty()) {
    pair<int, int> p1 = data.top();
    data.pop();
    if (data.empty()) {
      ans += (p1.first - 1);
      break;
    }
    pair<int, int> p2 = data.top();
    data.pop();
    if (p1.first != 1) {
      pair<int, int> p = make_pair(p1.first - 1, p1.second);
      data.push(p);
    }
    if (p2.first != 1) {
      pair<int, int> p = make_pair(p2.first - 1, p2.second);
      data.push(p);
    }
  }
  cout << ans << endl;
}
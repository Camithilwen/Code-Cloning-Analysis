#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<vector<int> > stx(n, vector<int>(3));
  for (auto &x: stx) cin >> x[0] >> x[1] >> x[2];
  vector<int> d(q);
  for (auto &x: d) cin >> x;

  for (auto &x: stx) {
    x[0] -= x[2];
    x[1] -= x[2];
  }

  vector<int> time, pos;
  priority_queue<Pii, vector<Pii>, greater<Pii> > pque;
  priority_queue<int, vector<int>, greater<int> > watching;
  unordered_set<int> roadblock;
  for (auto &x: stx) {
    pque.emplace(x[0], x[2]);
    pque.emplace(x[1], x[2]);
  }
  int lastTime = -1000000007;
  while (!pque.empty()) {
    auto now = pque.top();
    pque.pop();
    if (now.first > lastTime) {
      while (!watching.empty()) {
        auto next = watching.top();
        if (roadblock.find(next) == roadblock.end()) watching.pop();
        else break;
      }
      if (watching.empty()) {
        time.push_back(lastTime);
        pos.push_back(-1);
      }
      else {
        auto next = watching.top();
        time.push_back(lastTime);
        pos.push_back(next);
      }
      lastTime = now.first;
    }
    if (roadblock.find(now.second) == roadblock.end()) {
      roadblock.insert(now.second);
      watching.push(now.second);
    }
    else {
      roadblock.erase(now.second);
    }
  }
  time.push_back(lastTime);
  pos.push_back(-1);

  vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    auto it = upper_bound(time.begin(), time.end(), d[i]);
    int idx = distance(time.begin(), it) - 1;
    ans[i] = pos[idx];
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using P = pair<int, int>;

void solve(istream& cin, ostream& cout) {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n - 1));
  REP(i, n) {
    REP(j, n - 1) {
      cin >> a[i][j];
      a[i][j]--;
    }
    REVERSE(a[i]);
  }
  vector<P> que;
  auto check = [&](int i) {
    if (a[i].size() == 0) return;
    int j = a[i].back();
    if (a[j].back() == i) {
      if (i > j) que.push_back(P(j, i));
      else
        que.push_back(P(i, j));
    }
  };
  REP(i, n) {
    check(i);
  }
  int day = 0;
  while (que.size() > 0) {
    day++;
    SORT(que);
    que.erase(unique(que.begin(), que.end()), que.end());
    vector<P> prevQ;
    swap(prevQ, que);
    EACH(p, prevQ) {
      int i = p.first;
      int j = p.second;
      a[i].pop_back();
      a[j].pop_back();
    }
    EACH(p, prevQ) {
      int i = p.first;
      int j = p.second;
      check(i);
      check(j);
    }
  }
  REP(i, n) {
    if (a[i].size() != 0) {
      cout << -1 << endl;
      return;
    }
  }
  cout << day << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif

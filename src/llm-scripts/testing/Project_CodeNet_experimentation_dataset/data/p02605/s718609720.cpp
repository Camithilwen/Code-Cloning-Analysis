#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int main() {
  int N;
  cin >> N;

  using D = tuple<int, int, int>;
  vector<D> data;
  rep(i, N) {
    int x, y;
    char d;
    cin >> x >> y >> d;

    int dir = 0;
    if (d == 'D' || d == 'U') {
      dir |= 2;
    }
    if (d == 'D' || d == 'L') {
      dir |= 1;
    }
    data.push_back(D(x, y, dir));
  }

  constexpr int INF = numeric_limits<int>::max();
  int result = INF;

  constexpr int MAX = 200'000;
  vector<vector<vector<int>>> tbl(4, vector<vector<int>>(MAX + 1));
  vector<vector<vector<int>>> cross(4, vector<vector<int>>(2 * MAX + 1)),
      cross2(4, vector<vector<int>>(2 * MAX + 1));
  rep(i, N) {
    int x, y, d;
    tie(x, y, d) = data[i];

    tbl[d][((d & 2) ? x : y)].push_back((d & 2) ? y : x);
    cross[d][x + y].push_back(x - y + MAX);
    cross2[d][x - y + MAX].push_back(x + y);
  }
  rep(i, 4) irep(j, MAX) { sort(tbl[i][j].begin(), tbl[i][j].end()); }

  rep(i, 4) irep(j, 2 * MAX) {
    sort(cross[i][j].begin(), cross[i][j].end());
    sort(cross2[i][j].begin(), cross2[i][j].end());
  }

  rep(i, 2) {
    irep(j, MAX) {
      for (int v : tbl[i << 1][j]) {
        const auto &tmp = tbl[(i << 1) ^ 1][j];
        auto iter = lower_bound(tmp.begin(), tmp.end(), v);
        if (iter != tmp.end()) {
          // cerr << i << " " << j << " " << v << " " << *iter << "\n";
          chmin(result, 5 * (*iter - v));
        }
      }
    }
  }

  rep(i, 2) {
    irep(j, 2 * MAX) {
      for (int v : cross[i][j]) {
        const auto &tmp = cross[i ^ 2][j];
        auto iter = lower_bound(tmp.begin(), tmp.end(), v);
        if (i == 0) {
          if (iter != tmp.end()) {
            cerr << i << " " << j << " " << v << " " << *iter << "\n";
            chmin(result, 5 * (*iter - v));
          }
        } else {
          if (iter != tmp.begin()) {
            chmin(result, 5 * (v - *prev(iter)));
          }
        }
      }
    }
  }

  rep(i, 2) {
    irep(j, 2 * MAX) {
      for (int v : cross2[i][j]) {
        const auto &tmp = cross2[i ^ 3][j];
        auto iter = lower_bound(tmp.begin(), tmp.end(), v);
        if (i == 0) {
          if (iter != tmp.end()) {
            chmin(result, 5 * (*iter - v));
          }
        } else {
          if (iter != tmp.begin()) {
            chmin(result, 5 * (v - *prev(iter)));
          }
        }
      }
    }
  }

  if (result == INF) {
    cout << "SAFE" << endl;
  } else {
    cout << result << endl;
  }
  return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}

using namespace std;
using int64 = long long;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    cin >> a[i];
  }
  int n = 0;
  string ans = "";
  vector<int> od_row_idx;
  for (int i = 0; i < H; i++) {
    vector<int> od_idx;
    for (int j = 0; j < W; j++) {
      if (a[i][j] % 2 == 1) {
        od_idx.push_back(j);
      }
    }
    debug(od_idx);
    if ((int)od_idx.size() == 0) continue;
    for (int j = 0; j < (int)od_idx.size() - 1; j += 2) {
      for (int k = od_idx[j]; k < od_idx[j + 1]; k++) {
        ans += to_string(i + 1) + ' ' + to_string(k + 1) + ' ' +
               to_string(i + 1) + ' ' + to_string(k + 2) + '\n';
        n++;
      }
    }
    if ((int)od_idx.size() % 2 == 1) {
      for (int k = od_idx.back(); k < W - 1; k++) {
        ans += to_string(i + 1) + ' ' + to_string(k + 1) + ' ' +
               to_string(i + 1) + ' ' + to_string(k + 2) + '\n';
        n++;
      }
      od_row_idx.push_back(i);
    }
  }
  if ((int)od_row_idx.size() > 1) {
    for (int j = 0; j < (int)od_row_idx.size() - 1; j += 2) {
      for (int k = od_row_idx[j]; k < od_row_idx[j + 1]; k++) {
        ans += to_string(k + 1) + ' ' + to_string(W) + ' ' + to_string(k + 2) +
               ' ' + to_string(W) + '\n';
        n++;
      }
    }
  }
  cout << n << endl;
  cout << ans << endl;
  return 0;
}

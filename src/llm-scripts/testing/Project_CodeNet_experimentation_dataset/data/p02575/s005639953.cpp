#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& a) {
  os << "{";
  for (size_t i = 0; i < a.size(); ++i) os << (i > 0 ? "," : "") << a[i];
  return os << "}";
}

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

template <typename T, typename C>
ostream& operator<<(ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}
template <typename T1, typename T2, typename C>
ostream& operator<<(ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

int main() {
  int h, w;
  cin >> h >> w;
  // 右へ動く最小値を保管
  // ある点から始まった場合、
  // 複数の最短経路結果を持ちたい。
  //

  map<int, int> mp;
  multiset<int> st;
  rep(i, 0, w) {
    mp[i] = i;
    st.insert(0);
  }

  rep(i, 0, h) {
    int a, b;
    cin >> a >> b;
    --a;
    // [a, b]はいけない
    auto itr = mp.lower_bound(a);
    int most_right = -1;
    while (itr != mp.end() && itr->first <= b) {
      most_right = max(most_right, itr->second);
      int x = itr->first - itr->second;
      st.erase(st.find(x));
      itr = mp.erase(itr);
    }

    if (most_right != -1 && b < w) {
      st.insert(b - most_right);
      mp[b] = most_right;
    }
    if (st.size() > 0)
      cout << *st.begin() + i + 1 << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
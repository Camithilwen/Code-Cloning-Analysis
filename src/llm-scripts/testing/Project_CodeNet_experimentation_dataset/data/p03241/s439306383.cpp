#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
int N, M;

int main() {
  cin >> N >> M;
  vector<int> divs;
  for (int i = 1; i * i <= M; ++i) {
    if (M % i == 0) {
      divs.push_back(i);
      if (M / i != i) {
        divs.push_back(M / i);
      }
    }
  }
  sort(divs.begin(), divs.end());
  auto lb = lower_bound(divs.begin(), divs.end(), N);
  int nn = *lb;
  cout << M / nn << endl;
}

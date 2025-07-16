#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP2(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; ++i)
#define REP3(i, l, r) for (int i = (l), i##_len = (int)(r); i < i##_len; ++i)
#define GET_MACRO_REP(_1, _2, _3, NAME, ...) NAME
#define REP(...) GET_MACRO_REP(__VA_ARGS__, REP3, REP2) (__VA_ARGS__)
#define RREP2(i, n) for (int i = (n - 1); i >= 0; --i)
#define RREP3(i, l, r) for (int i = (r - 1), i##_len = (l); i >= i##_len; --i)
#define GET_MACRO_RREP(_1, _2, _3, NAME, ...) NAME
#define RREP(...) GET_MACRO_REP(__VA_ARGS__, RREP3, RREP2) (__VA_ARGS__)
#define IN(type, n) type n; cin >> n
#define INALL(type, v) REP(i, v.size()) { IN(type, _tmp); v.at(i) = _tmp; }
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#ifdef _DEBUG
#define DEBUG(x) cout << #x << ": " << x << endl
#else
#define DEBUG(x)
#endif

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#pragma endregion

int main() {
  IN(int, N);
  vector<ll> x(N);
  vector<ll> y(N);
  REP(i, N) {
    IN(ll, tmp_x);
    x.at(i) = tmp_x;
    IN(ll, tmp_y);
    y.at(i) = tmp_y;
  }

  cout << std::fixed << std::setprecision(6);

  vector<vector<long double> > dist(N, vector<long double>(N, 0));
  REP(i, N - 1) {
    REP(j, i + 1, N) {
      dist.at(i).at(j) = sqrtl((long double)(pow(x.at(i) - x.at(j), 2) + pow(y.at(i) - y.at(j), 2)));
      dist.at(j).at(i) = dist.at(i).at(j);
    }
  }

  vector<int> num;
  REP(i, 0, N) {
    num.push_back(i);
  }

  long double sum = 0;
  do {
    REP(i, N - 1) {
      sum += dist.at(num.at(i)).at(num.at(i + 1));
    }
  } while (next_permutation(ALL(num)));

  ll factorial = 1;
  REP(i, 1, N + 1) {
    factorial *= i;
  }

  long double ans = sum / (long double)factorial;
  cout << ans << endl;

  return 0;
}

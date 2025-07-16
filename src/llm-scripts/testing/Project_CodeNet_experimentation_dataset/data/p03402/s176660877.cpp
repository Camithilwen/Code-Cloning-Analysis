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

int A, B;

int main() {
  cin >> A >> B;

  int cnt_w = 1, cnt_b = 1;
  cout << 100 << " " << 100 << "\n";
  rep(h, 0, 50) {
    rep(w, 0, 100) {
      if (h % 2 == 0 && w % 2 == 0) {
        if (cnt_b < B) {
          cout << '#';
          ++cnt_b;
        } else {
          cout << ".";
        }
      } else {
        cout << ".";
      }
      if (w == 99) {
        cout << "\n";
      }
    }
  }

  rep(h, 50, 100) {
    rep(w, 0, 100) {
      if (h % 2 == 1 && w % 2 == 0) {
        if (cnt_w < A) {
          cout << '.';
          ++cnt_w;
        } else {
          cout << '#';
        }
      } else {
        cout << '#';
      }
      if (w == 99) {
        cout << "\n";
      }
    }
  }
}

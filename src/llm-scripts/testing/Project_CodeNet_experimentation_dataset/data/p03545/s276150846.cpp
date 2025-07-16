#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef long long ll;

typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<string> vs;

typedef pair<ll, ll> pll;
typedef pair<int, int> pi;

typedef vector<pll> vpl;
typedef vector<pi> vpi;
typedef vector<vs> vvs;

typedef vector<pll> vvpl;
typedef vector<vpi> vvpi;

typedef queue<ll> ql;
typedef queue<int> qi;
typedef queue<pll> qpl;
typedef queue<pi> qpi;

template <typename T> void printv(const vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("[%d] %d\n", i, v[i]);
  }
}

template <typename T> void printvv(const vector<T> &vv) {
  for (int i = 0; i < vv.size(); ++i) {
    for (int j = 0; j < vv[i].size(); ++j) {
      printf("[%d][%d] %d\n", i, j, vv[i][j]);
    }
  }
}

template <typename T, typename U> void printp(const pair<T, U> &p) {
  cout << p.first << " " << p.second << endl;
}

template <typename T> void printvp(const vector<pair<T, T>> &vp) {
  for (int i = 0; i < vp.size(); ++i) {
    printf("[%d] %d, %d\n", vp[i].first, vp[i].second);
  }
}

template <typename T> void printvvp(const vector<vector<pair<T, T>>> &vvp) {
  for (int i = 0; i < vvp.size(); ++i) {
    for (int j = 0; j < vvp[i].size(); ++j) {
      printf("[%d][%d] %d, %d\n", i, j, vvp[i][j].first, vvp[i][j].second);
    }
  }
}

int main() {
  string S;
  cin >> S;

  ll tmp = 0;
  for (int bit = 0; bit < (1 << (S.length() - 1)); ++bit) {
    tmp = S[0] - '0';
    for (int i = 1; i < S.length(); ++i) {
      if (bit & 1 << (i - 1)) {
        tmp += S[i] - '0';
      } else {
        tmp -= S[i] - '0';
      }
    }
    if (tmp == 7) {
      for (int i = 0; i < S.length(); ++i) {
        cout << S[i];
        if (i < S.length() - 1) {
          char op = (bit & (1 << i)) >= 1 ? '+' : '-';
          cout << op;
        }
      }
      cout << "=7" << endl;
      break;
    }
  }
  return 0;
}

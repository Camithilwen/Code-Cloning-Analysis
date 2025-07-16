#ifndef Local
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

using namespace std;

#define popCnt(x) (__builtin_popcountll(x))
#define sz(x) ((int)(x.size()))
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
typedef long long Long;
typedef double Double;

template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}

template <class T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}

const int N = 303;
const int MOD = 998244353;
int memo[N][N][N];

vector<int> v;
int count(int ind, int ones, int k) {
  if (k < 0) return 0;
  if (ones < 0) return 0;
  if (ind == 0) return 1;
  int& res = memo[ind][ones][k];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i <= v[ind] + ones; ++i) {
    res =
        (res + count(ind - 1, v[ind] + ones - i, k - max(0, v[ind] - i))) % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  string s;
  int k;
  cin >> s >> k;

  memset(memo, -1, sizeof memo);
  v.emplace_back(0);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      ++v.back();
    } else {
      v.emplace_back(0);
    }
  }

  cout << count(sz(v) - 1, 0, min(N - 1, k)) << endl;

  return 0;
}
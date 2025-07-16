#pragma region

#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _rep3(i, begin, end) for (register int i = (begin); i < (end); i++)
#define _irep3(i, begin, end) for (register int i = (end)-1; i >= (begin); i--)
#define _rep2(i, n) _rep3(i, 0, n)
#define _irep2(i, n) _irep3(i, 0, n)
#define _overload3(_1, _2, _3, name, ...) name
#define rep(...) _overload3(__VA_ARGS__, _rep3, _rep2, )(__VA_ARGS__)
#define irep(...) _overload3(__VA_ARGS__, _irep3, _irep2, )(__VA_ARGS__)
#define out(x) cout << (x) << '\n';
#define debug(x) cerr << #x << " = " << (x) << " (line: " << __LINE__ << ") " << endl;
typedef long long ll;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "vec[ ";
  rep(i, vec.size()) i == 0 ? os << vec[i] : os << ", " << vec[i];
  os << " ]";
  return os;
}

#pragma endregion

#define MOD 1000000007
#define INF 2147483647

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(16);

  ll N;
  cin >> N;
  if (N == 2) {
    out(-1);
    return 0;
  }
  if (N == 3) {
    out("abb");
    out("a.a");
    out("bba");
    return 0;
  }
  if (N == 4) {
    out("abaa");
    out("abcc");
    out("ccba");
    out("aaba");
    return 0;
  }
  vector<string> ans(N, string(N, '.'));
  ans[0][0] = 'c';
  ans[0][1] = 'c';
  ans[1][0] = 'd';
  ans[2][0] = 'd';
  ans[0][N - 1] = 'c';
  ans[1][N - 1] = 'c';
  ans[0][N - 2] = 'd';
  ans[0][N - 3] = 'd';
  ans[N - 1][N - 1] = 'c';
  ans[N - 1][N - 2] = 'c';
  ans[N - 2][N - 1] = 'd';
  ans[N - 3][N - 1] = 'd';
  ans[N - 1][0] = 'c';
  ans[N - 2][0] = 'c';
  ans[N - 1][1] = 'd';
  ans[N - 1][2] = 'd';
  rep(i, N - 4) {
    char c = i % 2 == 0 ? 'a' : 'b';
    ans[i + 1][i + 2] = c;
    ans[i + 1][i + 3] = c;
    ans[i + 2][i + 1] = c;
    ans[i + 3][i + 1] = c;
  }
  rep(i, N) out(ans[i]);
}

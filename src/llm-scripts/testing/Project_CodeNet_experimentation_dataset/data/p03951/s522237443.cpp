#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  string s, t;
  int N;
  cin >> N >> s >> t;
  REP(i, N) {
    if (s.substr(i, N - i) == t.substr(0, N - i)) {
      cout << 2 * N - (N - i) << endl;
      return 0;
    }
  }
  cout << 2 * N << endl;
}
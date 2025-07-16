#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/abc045_b.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string A, B, C;
  cin >> A >> B >> C;

  int a = 0, b = -1, c = -1;
  char next = 'a';
  while (true) {
    if (next == 'a') {
      a++;
      if (a == A.size()) {
        cout << "A" << endl;
        return 0;
      }
      next = A[a];
    } else if (next == 'b') {
      b++;
      if (b == B.size()) {
        cout << "B" << endl;
        return 0;
      }
      next = B[b];
    } else {
      c++;
      if (c == C.size()) {
        cout << "C" << endl;
        return 0;
      }
      next = C[c];
    }
  }
}
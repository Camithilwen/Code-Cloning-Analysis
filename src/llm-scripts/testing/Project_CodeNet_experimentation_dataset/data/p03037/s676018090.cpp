#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const int INF = (1<<21);
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int N, M; cin >> N >> M;
  int maxL = 0;
  int minR = N;
  for (int i = 0; i < M; ++i) {
    int l ,r; cin >> l >> r;
    maxL = max(maxL, l);
    minR = min(minR, r);
  }
  int ans = minR - maxL + 1;
  if (ans < 0) cout << 0 << endl;
  else cout << ans << endl;
}

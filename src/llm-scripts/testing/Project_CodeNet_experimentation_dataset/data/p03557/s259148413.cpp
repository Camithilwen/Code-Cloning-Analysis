#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;

int n;
vector<vector<int>> a(3);

ll solve () {
  ll ans = 0;
  rep (j, n) {
    int tmp = a[1][j];
    ll comb = lower_bound(a[0].begin(), a[0].end(), tmp) - a[0].begin();
    comb *= a[2].end() - upper_bound(a[2].begin(), a[2].end(), tmp);
    ans += comb;
  }
  return ans;
}

int main() {
  while (cin >> n) {
    rep (i, 3) {
      a[i].resize(n);
      rep (j, n) cin >> a[i][j];
      sort(a[i].begin(), a[i].end());
    }
    cout << solve() << endl;
  }
  return 0;
}

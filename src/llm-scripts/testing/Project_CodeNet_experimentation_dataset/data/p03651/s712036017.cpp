#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
typedef complex<double> cd;
static const double pi = 3.141592653589793;

int gcd(int a, int b) {
  if(b > a) swap(a, b);
  if(a % b == 0) return b;
  return gcd(b, a % b);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k; cin >> n >> k;
  int curGcd; cin >> curGcd;
  int maxA = curGcd;
  rep(i, n - 1) {
    int tmp; cin >> tmp;
    chmax(maxA, tmp);
    curGcd = gcd(curGcd, tmp);
  }

  if(k <= maxA && k % curGcd == 0) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}

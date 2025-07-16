#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

int N;
vector<int> A, sum;

signed main() {
  cin >> N;

  A.resize(N);
  REP(i, N) cin >> A[i];

  sum.resize(N+1, 0);
  REP(i, N) sum[i+1] += sum[i]+A[i];

  auto f = [&](int l, int m, int r){
    return abs((sum[m]-sum[l])-(sum[r+1]-sum[m]));
  };

  int ans = INF;
  int l = 1, r = 2;
  FOR(i, 1, N-1){
    while(l+1 <= i && f(0, l, i) > f(0, l+1, i)) l++;
    while(r+1 <= N && f(i+1, r, N-1) > f(i+1, r+1, N-1)) r++;

    int P = sum[l];
    int Q = sum[i+1]-sum[l];
    int R = sum[r]-sum[i+1];
    int S = sum[N]-sum[r];

    int MAX = max(max(P, Q), max(R, S));
    int MIN = min(min(P, Q), min(R, S));

    chmin(ans, MAX-MIN);
  }

  cout << ans << "\n";


  return 0;
}
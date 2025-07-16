#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
 
using namespace std;
typedef long long ll;
using gra = vector<vector<ll>>;
using gram = vector<unordered_map<ll,ll>>;
 
typedef unsigned long long ull;
 
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
 
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> T dup(T a, T b) { return (a + b - 1) / b; }
template <class T> T modpow(T x, T p, T m) { T a=1; while(p){ if(p%2)a =a*x%m; x = x+x%m; p/=2; } return a; }
// template <class T> void prim(T a) { for(ll i=0;i<a.size();++i) { cout << a[i]; } cout << "\n"; }
//template< typename T >
//T mod_pow(T x, T n, const T &p) {
//  T ret = 1;
//  while(n > 0) {
//    if(n & 1) (ret *= x) %= p;
//    (x *= x) %= p;
//    n >>= 1;
//  }
//  return ret;
//}
/////////////////// 
//

#define mod 1000000007LL
#define INF 10000000000000000LL
 
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep1(i, n) for (ll i = 1; i <= n; ++i)
#define rrep(i, n) for (int i = (n - 1); i >= 0; --i)
#define rrep1(i, n) for (int i = n; i > 0; --i)
 
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
//#define modpow(x, p, m) { ll a=1; while(p){ if(p%2)a =a*x%m; x = x+x%m; p/=2; } return a; }
 
#define m0(h) memset(h, 0, sizeof(h))
#define m1(h) memset(h, 1, sizeof(h))
#define m(h, n) memset(h, (n), sizeof(h))
#define all(n) (n).begin(),(n).end()
#define bit(n) (1LL << (n))
#define pb push_back
#define mp make_pair
 
//#ifdef LOCAL
//
//#define dpri(...) fprintf(stderr, __VA_ARGS__)
//#define pria(g) rep(i,g.size()){ cout << i << "{"; rep(j,g[i].size()) cout << g[i][j] << " "; cout << "}" << "\n"; }
//#else
//#define dpri(...) 42
//#define pria(g) 42
//#endif
//
//
//

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // ---------------------
  // コーディング開始
  // ---------------------
  string a;
  cin >> a;
  if(a.length()==2) cout << a << endl;
  else cout << a[2] << a[1] << a[0] << endl;
  return 0;
}






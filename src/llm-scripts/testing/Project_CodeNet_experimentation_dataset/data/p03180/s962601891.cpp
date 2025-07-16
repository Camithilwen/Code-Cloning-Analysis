#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<class T>using vv = vector<vector<T>>;
using vvi = vv<int>;
using vvl = vv<long long>;

#define in(v) v; cin >> v;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}

#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define repi(i,a,b) for(int i=(a),_i=(b);i<_i;++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

// debug
template<class T>ostream& operator<<(ostream& os,const vector<T>& vec){os<<"{";for(size_t i=0;i<vec.size();++i)os<<(i?", ":"")<<vec[i];os<<"}";return os;}
ostream& operator<<(ostream& os,const vector<char>&v){for(size_t i=0;i<v.size();++i)os<<v[i];return os;}
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>& rhs){os<<"("<<rhs.first<<", "<<rhs.second<<")";return os;}

#ifdef LOCAL
void debug() {cerr << "\n";}
template<class First> void debug(const First& first) {cerr<<first<<"\n";}
template<class First, class... Rest> void debug(const First& first, const Rest&... rest) {cerr<<first<<",";debug(rest...);}
void debug2() {cerr << "\n";}
template<class First> void debug2(const First& first) {cerr<<first<<" ";}
template<class First, class... Rest> void debug2(const First& first, const Rest&... rest) {cerr<<first<<" ";debug2(rest...);}
#else
#define debug(...) 42
#define debug2(...) 42
#endif

int N;
vv<int> A;
ll dp[1<<16][16];
const ll INF = 1e15;
ll dfs(int used, int i) {
  if (i == N)
    return 0;

  if (dp[used][i] != INF)
    return dp[used][i];

  if (used & (1 << i))
    return dfs(used, i+1);

  ll ans = 0;

  vi notUsed;
  rep(j, N)
    if (!(used & (1 << j))) {
      if (j < i)
        return -INF;
      notUsed.push_back(j);
    }

  rep(bit, 1 << (notUsed.size())) {
    ll tmp = 0;
    int used2 = 0;
    rep(j, notUsed.size()) {
      if (bit & (1 << j)) {
        used2 |= 1 << notUsed[j];
        rep(k, j+1, notUsed.size()) {
          if (bit & (1 << k))
            tmp += A[notUsed[j]][notUsed[k]];
        }
      }
    }
    ans = max(ans, tmp + dfs(used | used2, i+1));
  }
  return dp[used][i] = ans;
}
int main() {
  in(N);
  A.resize(N, vector<int>(N, 0));

  rep(i, 1<<16) rep(j, 16) dp[i][j] = INF;
  rep(i, N) rep(j, N) {
    cin >> A[i][j];
  }
  cout << dfs(0, 0) << endl;

  return 0;
}

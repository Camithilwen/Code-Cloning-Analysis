#include <bits/stdc++.h> // {{{

#define ARG4(_1, _2, _3, _4, ...) _4
#define rep(...) ARG4(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define REP(i, a) FOR(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define rrep(...) ARG4(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define RREP(i, a) RFOR(i, 0, a)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (int)(a); --i)
#define ALL(c) (c).begin(), (c).end()
#define TEN(n) ((ll)(1e##n))
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define let const auto
#define USE_T template <typename T>
#define USE_Ti template <typename T = int>
#define USE_TU template <typename T, typename U>

USE_Ti using duo = std::pair<T, T>;
USE_Ti using vec = std::vector<T>;
using ll = long long;
// clang-format off
USE_TU inline bool chmax(T&x,U a){return x<a&&(x=a,1);}
USE_TU inline bool chmin(T&x,U a){return a<x&&(x=a,1);}
USE_Ti inline T in(){T x;std::cin>>x;return x;}
USE_Ti inline vec<T> in(int n){vec<T> v;v.reserve(n);rep(i,n)v.pb(in<T>());return v;}
USE_T inline void in(T*x,int n){rep(i,n)x[i]=in<T>();}
struct IoSetup {
  IoSetup(){
    using namespace std;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<setprecision(10);
    cerr<<setprecision(10);
  }
} iosetup;
// clang-format on
// }}}
using namespace std;
const int inf = 1001001001;
const ll infll = 1001001001001001001ll;
const int dd[] = {0, 1, 0, -1, 0};

signed main() {
  auto S = in(6);
  int tot = std::accumulate(ALL(S), 0);
  tot -= *min_element(ALL(S) - 2);
  tot -= *min_element(4 + ALL(S));
  cout << tot << endl;
  return 0;
}
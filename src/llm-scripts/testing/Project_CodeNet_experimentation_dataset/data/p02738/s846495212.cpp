#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int n,m;
int mul(int a,int b){
  return a * b % m;
}
void add(int &a,int b){
  a += b;
  if(a >= m)
    a -= m;
}
int po2(int a){
  return (a-2) * (a - 1) % m;
}
// int odw3 = 1;
// int po3(int a){
//   return a * (a - 1) % m * (a - 2) % m * odw3 % m;
// }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  vector<int> zost(3 * n + 1);
//   while(odw3 % 3 != 0)odw3 += m;
//   odw3 /= 3;
  zost[3*n] = 1;
  int res = 0;
  R(_,n+1){
    debug(zost);
    R(i,SZ(zost))add(res, zost[i]);
    debug(res);
    if(_ == n)break;
    
    for(int i = 3 * n - 1; i >= 0; i--){
      add(zost[i], zost[i + 1]);
    }
    
    vector<int> ak(3 * n + 1);
    R(i,SZ(zost)){
      if(i >= 2)add(ak[i - 2], mul(i-1, zost[i]));
      if(i >= 3)add(ak[i - 3], mul(po2(i), zost[i]));
    }
    swap(ak, zost);
  }
    
  cout << res << "\n";
}

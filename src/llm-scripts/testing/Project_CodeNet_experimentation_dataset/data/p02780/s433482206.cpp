#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  //in
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  //
  
  int ex = 0;
  //前処理
  REP(i,k){
    int px = p[i]+1;
    ex += px;
  }
  int exmax = ex;

  REP2(i,k,n){
    ex -= p[i-k];
    ex += p[i];
    exmax = max(ex,exmax);
  }

  double ans = (double)exmax/2;

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
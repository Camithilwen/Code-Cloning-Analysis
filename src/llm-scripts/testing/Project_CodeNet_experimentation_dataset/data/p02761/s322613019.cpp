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
  //input
  int n, m;
  cin >> n >> m;
  vector<int> s(m), c(m);
  REP(i,m) {
    int sx, cx;
    cin >> sx >> cx;
    sx--;
    s[i] = sx;
    c[i] = cx;
  }
  debug(s);
  debug(c);

  vector<int> a(n, -1);
  debug(a);

  REP(i,m){
    // if((s[i] == 0) && (c[i] == 0)){
    //     cout << -1 << endl;
    //     return 0;
    // }
    if((a[s[i]] != -1) && (a[s[i]] != c[i])){
      cout << -1 << endl;
      return 0;
    }
    a[s[i]] = c[i];
    debug(a);
  }

  if(n == 1){
    if(a[0] == -1) a[0] = 0;
    cout << a[0] << endl;
    return 0;
  }

  if(a[0] == 0){
    cout << -1 << endl;
    return 0;
  }

  REP(i,n){
    if(a[i] == -1){
      if(i == 0) a[i] = 1;
      else a[i] = 0;
    }
  }

  int ans = 0;
  REP(i,n){
    ans *= 10;
    ans += a[i];
  }

  cout << ans << endl;
  
  return 0;
}
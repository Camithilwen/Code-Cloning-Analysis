#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

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
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
const int INF = 1e18;

using namespace std;


signed main() {
  int N;
  cin >> N;
  if(N == 2){
    cout << -1 << endl;
    return 0;
  }else if(N == 3){
    cout << "aa." << endl;
    cout << "..a" << endl;
    cout << "..a" << endl;
    return 0;
  }

  int x, y;
  if(N%4 == 0){
    x = N/4;
    y = 0;
  }else{
    x = N/4-1;
    y = N-(N/4-1)*4;
  }

  vector<vector<char>> vec(N, vector<char>(N, '.'));

  REP(i, x){
    vec[i*4+0][i*4+0] = 'a';
    vec[i*4+0][i*4+1] = 'a';
    vec[i*4+0][i*4+2] = 'b';
    vec[i*4+0][i*4+3] = 'c';
    vec[i*4+1][i*4+0] = 'd';
    vec[i*4+1][i*4+1] = 'd';
    vec[i*4+1][i*4+2] = 'b';
    vec[i*4+1][i*4+3] = 'c';
    vec[i*4+2][i*4+0] = 'b';
    vec[i*4+2][i*4+1] = 'c';
    vec[i*4+2][i*4+2] = 'a';
    vec[i*4+2][i*4+3] = 'a';
    vec[i*4+3][i*4+0] = 'b';
    vec[i*4+3][i*4+1] = 'c';
    vec[i*4+3][i*4+2] = 'd';
    vec[i*4+3][i*4+3] = 'd';
  }
  REP(i, x*4) REP(j, x*4){
    cout << vec[i][j];
    if(j == x*4-1){
      REP(k, y) cout << '.';
      cout << endl;
    }
  }


  if(y == 5){
    REP(i, x*4) cout << '.'; cout << "aabba" << endl;
    REP(i, x*4) cout << '.'; cout << "bcc.a" << endl;
    REP(i, x*4) cout << '.'; cout << "b..cb" << endl;
    REP(i, x*4) cout << '.'; cout << "a..cb" << endl;
    REP(i, x*4) cout << '.'; cout << "abbaa" << endl;
  }else if(y == 6){
    REP(i, x*4) cout << '.'; cout << "aabc.." << endl;
    REP(i, x*4) cout << '.'; cout << "ddbc.." << endl;
    REP(i, x*4) cout << '.'; cout << "..aabc" << endl;
    REP(i, x*4) cout << '.'; cout << "..ddbc" << endl;
    REP(i, x*4) cout << '.'; cout << "bc..aa" << endl;
    REP(i, x*4) cout << '.'; cout << "bc..dd" << endl;
  }else if(y == 7){
    REP(i, x*4) cout << '.'; cout << "aabbcc." << endl;
    REP(i, x*4) cout << '.'; cout << "dd.dd.a" << endl;
    REP(i, x*4) cout << '.'; cout << "..d..da" << endl;
    REP(i, x*4) cout << '.'; cout << "..d..db" << endl;
    REP(i, x*4) cout << '.'; cout << "dd.dd.b" << endl;
    REP(i, x*4) cout << '.'; cout << "..d..dc" << endl;
    REP(i, x*4) cout << '.'; cout << "..d..dc" << endl;
  }

  return 0;
}
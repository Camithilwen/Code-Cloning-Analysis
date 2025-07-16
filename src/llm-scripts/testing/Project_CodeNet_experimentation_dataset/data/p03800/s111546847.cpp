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
#include <bitset>

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
  string s;
  cin >> N >> s;

  vector<int> vec(N, INF);
  int x[] = {0, 0, 1, 1};
  int y[] = {0, 1, 0, 1};
  REP(_, 4){
    vec[0] = x[_];
    vec[1] = y[_];
    FOR(i, 1, N-1){
      // hituzi
      if(vec[i] == 1){
        if(s[i] == 'o') vec[i+1] = vec[i-1];
        else vec[i+1] = 1-vec[i-1];
      }else{
        if(s[i] == 'x') vec[i+1] = vec[i-1];
        else vec[i+1] = 1-vec[i-1];
      }
    }
    int ans = 0;
    if(vec[N-1] == 1){
      if(s[N-1] == 'o' && vec[N-2] == vec[0]) ans++;
      if(s[N-1] == 'x' && vec[N-2] != vec[0]) ans++;
    }else{
      if(s[N-1] == 'x' && vec[N-2] == vec[0]) ans++;
      if(s[N-1] == 'o' && vec[N-2] != vec[0]) ans++;
    }
    if(vec[0] == 1){
      if(s[0] == 'o' && vec[N-1] == vec[1]) ans++;
      if(s[0] == 'x' && vec[N-1] != vec[1]) ans++;
    }else{
      if(s[0] == 'x' && vec[N-1] == vec[1]) ans++;
      if(s[0] == 'o' && vec[N-1] != vec[1]) ans++;
    }
    if(ans == 2){
      REP(i, N){
        if(vec[i]) cout << "S";
        else cout << "W";
      }
      cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
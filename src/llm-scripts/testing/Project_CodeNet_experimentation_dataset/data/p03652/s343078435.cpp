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
#include <complex>
#include <functional>

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
/* const int MOD = 1000000007; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> A(N, vector<int>(M));
  REP(i, N) REP(j, M){
    cin >> A[i][j];
    A[i][j]--;
  }

  int ans = N;
  vector<int> cnt(N, 0);
  vector<int> ng;

  while((int)ng.size() < M-1){
    vector<int> num(M, 0);
    REP(i, N){
      num[A[i][cnt[i]]]++;
    }

    int ret = 0;
    REP(i, M) if(num[i] != 0) chmax(ret, num[i]);
    chmin(ans, ret);


    pair<int, int> p(0, 0);
    REP(i, M){
      if(p.first < num[i]){
        p.first = num[i];
        p.second = i;
      }
    }
    ng.emplace_back(p.second);

    REP(i, N){
      REP(j, ng.size()){
        if(A[i][cnt[i]] == ng[j]){
          cnt[i]++;
          j = -1;
        }
      }
    }
  }

  cout << ans << endl;
  

  return 0;
}
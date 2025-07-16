#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[10010];
  
int main()
{
  int K,T;
  cin >> K >> T;
  vector<int> A(T);
  REP(i, T) cin >> A[i];
  
  sort(ALL(A));
  int sum = 0;
  REP(i,T-1){
    sum+=A[i];
  }
  cout << max(0,A[T-1]-1-sum) << endl;
}
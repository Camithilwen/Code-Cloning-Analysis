#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  REP(i, M) cin >> A[i];
  vector<int> num = {0,2,5,5,4,5,6,3,7,6};
  vector<string> dp(N+1, "x");
  dp[0] = "";
  FOR(i, 1, N+1) {
    REP(j, M) {
      if(i-num[A[j]] >= 0) {
        if(dp[i-num[A[j]]] == "x") continue;
        if(dp[i] == "x" || dp[i-num[A[j]]].size() >= dp[i].size()) {
          dp[i] = dp[i-num[A[j]]] + (char)(A[j] + '0');
        } else if(dp[i-num[A[j]]].size() + 1 == dp[i].size()) {
          dp[i] = max(dp[i], dp[i-num[A[j]]] + (char)(A[j] + '0'));
        }
      }
    }
    //cout << dp[i] << endl;
  }
  cout << dp[N] << endl;
}
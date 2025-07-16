#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
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
  int N;
  cin >> N;
  string S;
  cin >> S;
  string S1 = S.substr(0, N);
  string S2 = S.substr(N, N);
  lint ans = 0;
  REP(k, 1<<N) {
    string a = "";
    string b = "";
    REP(i, N) {
      if((k>>i&1) == 1) {
        a = S1[i] + a;
      } else {
        b = S1[i] + b;
      }
    }
    vector<vector<lint>> dp(N+1, vector<lint>(a.size()+1));
    dp[0][0] = 1;
    REP(i, N) {
      REP(j, a.size()+1) {
        if(j != a.size() && S2[i] == a[j]) {
          dp[i+1][j+1] += dp[i][j];
        }
        if(S2[i] == b[i-j]) {
          dp[i+1][j] += dp[i][j];
        }
      }
    }
    ans += dp[N][a.size()];
  }
  cout << ans << endl;
}
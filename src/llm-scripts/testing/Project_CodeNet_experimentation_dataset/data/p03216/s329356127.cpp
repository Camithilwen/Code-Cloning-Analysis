#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll dp[1000010][5];

int main(){
  ll N;
  string S;
  ll Q;
  cin >> N >> S >> Q;
  vector<ll> k(Q),ans(Q);
  rep(i,Q) cin >> k[i];
  rep(j,Q){
    dp[0][0] = 0;
    ll D = 0,M = 0,K = k[j];
    rep(i,N){
      if(S[i] == 'D'){
        D++;
        dp[i+1][0] = dp[i][0] + 1;
        dp[i+1][1] = dp[i][1];
        dp[i+1][2] = dp[i][2];
        if(i - K >= 0){
          if(S[i-K] == 'D'){
            D--;
            dp[i+1][0]--;
            dp[i+1][1] -= M;
          }
          if(S[i-K] == 'M') M--;
        }
      }else if(S[i] == 'M'){
        M++;
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1] + dp[i][0];
        dp[i+1][2] = dp[i][2];
        if(i - K >= 0){
          if(S[i-K] == 'D'){
            D--;
            dp[i+1][0]--;
            dp[i+1][1] -= M;
          }
          if(S[i-K] == 'M') M--;
        }
      }else if(S[i] == 'C'){
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        dp[i+1][2] = dp[i][2] + dp[i][1];
        if(i - K >= 0){
          if(S[i-K] == 'D'){
            D--;
            dp[i+1][0]--;
            dp[i+1][1] -= M;
            dp[i+1][2] -= M;
          }
          if(S[i-K] == 'M') M--;
        }
      }else{
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        dp[i+1][2] = dp[i][2];
        if(i - K >= 0){
          if(S[i-K] == 'D'){
            D--;
            dp[i+1][0]--;
            dp[i+1][1] -= M;
          }
          if(S[i-K] == 'M') M--;
        }
      }
    }
    ans[j] = dp[N][2];
  }
  rep(i,Q) cout << ans[i] << endl;
}

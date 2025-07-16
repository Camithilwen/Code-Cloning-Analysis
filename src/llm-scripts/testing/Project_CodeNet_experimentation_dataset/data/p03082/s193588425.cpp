#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  int N, X; cin >> N >> X; int S[N];
  rep(i, N){
    cin >> S[i];
  }
  sort(S, S+N);
  ll dp[N+1][X+1] = {};
  rep(i, X+1){
    dp[0][i] = i;
  }
  rep(i, N){
    rep(j, X+1){
      dp[i+1][j] = dp[i][j%S[i]] + i*dp[i][j];
      dp[i+1][j]%=mod;
    }
  }
  cout << dp[N][X] << endl;
}
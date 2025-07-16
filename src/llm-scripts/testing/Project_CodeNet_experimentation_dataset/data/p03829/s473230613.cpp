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

int main()
{
  ll N,A,B;
  cin >> N >> A >> B;
  vector<ll> X(N);
  REP(i, N) cin >> X[i];
  
  ll ans=0;
  REP(i,N-1){
    if((X[i+1]-X[i])*A>=B){
      ans+=B;
    }else{
      ans+=(X[i+1]-X[i])*A;
    }
  }
  cout << ans << endl;
}
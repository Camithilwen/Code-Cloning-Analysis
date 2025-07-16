#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  int flag = (A[0]!=0);
  REP(i,N-1){
    if(A[i]+2<=A[i+1]){
      flag=1;
    }
  }
  if(flag==1){
    cout << -1 << endl;
  }else{
    ll ans = 0;
    A.push_back(0);
    REP(i,N){
      if((A[i]>=A[i+1])){
        ans+=A[i];
      }
    }

    cout << ans << endl;
  }
}
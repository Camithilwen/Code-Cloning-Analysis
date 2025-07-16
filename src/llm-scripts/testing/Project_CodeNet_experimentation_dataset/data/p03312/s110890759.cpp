#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int N; cin>>N;
  vi A(N);
  rep(i,0,N) cin>>A[i];
  vi dp(N+1);
  rep(i,0,N) dp[i+1]=dp[i]+A[i];
  int ans=INF;
  REP(i,2,N){
    int X=disup(dp,dp[i]/2),Y=disup(dp,(dp[i]+dp[N])/2);
    rep(j,0,(1ll<<2)){
      bitset<2> B(j);
      int P=X,Q=Y;
      if(B.test(0)) P--;
      if(B.test(1)) Q--;
      vi C(4);
      C[0]=dp[P];
      C[1]=dp[i]-dp[P];
      C[2]=dp[Q]-dp[i];
      C[3]=dp[N]-dp[Q];
      sort(ALL(C));
      if(C[0]>0) ans=min(ans,C[3]-C[0]);
    }
  }
  cout<<ans<<endl;
  }

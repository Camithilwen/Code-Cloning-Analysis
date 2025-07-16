#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)
using namespace std;
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int dp[509][509];
int C[509][509];
int recurr(int i,int j){
  if(dp[i][j]!=-1) return dp[i][j];
  if(i==j) {dp[i][j]=C[i][j]; return dp[i][j];}
  // number of line segements b/w i & j = line segement from i to j and line segments b/w i to j-1
  // and line segments b/w i+1 to j - line segments included in both(i to j-1, i+1 to j) range i.e i+1 to j-1
  dp[i][j]=C[i][j]+recurr(i,j-1)+recurr(i+1,j)-recurr(i+1,j-1);
  return dp[i][j];
}
void  solve(){
  int n,m,Q,l,r;
  cin>>n>>m>>Q;
  rep(i,0,m){
    cin>>l>>r;
    C[l][r]++;
  }
  rep(i,1,n+1) rep(j,1,n+1) dp[i][j]=-1;

  recurr(1,n);

  rep(i,0,Q){
    cin>>l>>r;
    cout<<dp[l][r]<<endl;
  }

}
int main(){
    optimizeIO();
    solve();
}

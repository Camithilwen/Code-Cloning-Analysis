#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int dp[3005][3005];

int main(){
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  vector<int> b(n);
  vector<P> ab(n);
  rep(i, n){
    cin >> a[i] >> b[i];
    ab[i]=P(a[i], b[i]);
  }
  sort(ab.begin(), ab.end());
  rep(i, n){
    a[i]=ab[i].first;
    b[i]=ab[i].second;
  }
  rep(i, n){
    rep(j, t){
      if(j-a[i]<0){
        dp[i+1][j]=dp[i][j];
      } else {
        dp[i+1][j]=max(dp[i][j], dp[i][j-a[i]]+b[i]);
      }
    }
  }
  int ans=0;
  rep(i, n){
    ans=max(dp[i][t-1]+b[i], ans);
  }
  cout << ans << endl;
  return 0;
}

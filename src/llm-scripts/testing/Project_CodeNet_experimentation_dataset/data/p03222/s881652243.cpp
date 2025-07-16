#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007LL;

ll dp[110][10];
bool memo[110][10];
vector<ll> a;
ll W;

ll f(ll i, ll j){
  if(memo[i][j]) return dp[i][j];
  memo[i][j]=true;
  dp[i][j]=0LL;
  if(j>=2) dp[i][j]+=(f(i-1,j-1)*(a[j-2]*a[W-j]))%mod;
  dp[i][j]+=(f(i-1,j)*(a[j-1]*a[W-j]))%mod;
  if(j<=W-1) dp[i][j]+=(f(i-1,j+1)*(a[j-1]*a[W-j-1]))%mod;
  dp[i][j]%=mod;
  return dp[i][j];
}

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll H,K;
  cin>>H>>W>>K;
  a.assign(W+1,1LL);
  for(ll i = 2LL;i <= W;i++){
    a[i]=a[i-1LL]+a[i-2LL];
  }
  memo[0][1]=true;
  dp[0][1]=1LL;
  for(int i = 2;i <=W;i++){
    memo[0][i]=true;
    dp[0][i]=0LL;
  }
  cout<<f(H,K)<<endl;
}
  
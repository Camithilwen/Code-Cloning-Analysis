#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;
long long modpow(long long x,long long n,long long mod)
{
  if(n==0)return 1;
  long long res=modpow(x*x%mod,n/2,mod);
  if(n&1)res=res*x%mod;
  return res;
}
long long modinv(long long a,long long mod)//extgcdの方がいいらしい
{
  return modpow(a,mod-2,mod);
}
vector<int>inv;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,x;
  int mod=1e9+7;
  cin>>n>>x;
  vector<int>s(n);
  rep(i,n)cin>>s[i];
  sort(all(s),greater<int>());
  inv.resize(n+1);
  repi(i,1,n+1)inv[i]=modinv(i,mod);
  vector<vector<int>>dp(2,vector<int>(x+1,0));
  dp[0][x]=1;
  rep(i,n)
  {
    int no=i&1,ne=1-no;
    fill(all(dp[ne]),0);
    rep(j,x+1)
    {
      if(dp[no][j]==0)continue;
      int t=(ll)dp[no][j]*inv[n-i]%mod;
      int jsi=j%s[i];
      dp[ne][jsi]+=t;
      dp[ne][j]+=(ll)t*(n-i-1)%mod;
      if(dp[ne][jsi]>mod)dp[ne][jsi]-=mod;
      if(dp[ne][j]>mod)dp[ne][jsi]-=mod;
    }
  }
  int  res=0;
  int kai=1;
  rep(i,n)kai=(ll)kai*(i+1)%mod;
  rep(i,x+1)
  {
    res+=(ll)kai*dp[n&1][i]%mod*i%mod;
    if(res>mod)res-=mod;
  }
  cout<<res<<endl;


  return 0;

}

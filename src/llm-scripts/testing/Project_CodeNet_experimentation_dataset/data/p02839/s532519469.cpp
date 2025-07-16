#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int DP[85][85][30000]; 

int main() {
  int H, W;
  cin>>H>>W;
  int A[H][W], B[H][W];
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>A[i][j];
    }
  }
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>B[i][j];
    }
  }
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      A[i][j] -= B[i][j];
    }
  }
  DP[0][0][15000+A[0][0]] = 1;
  DP[0][0][15000-A[0][0]] = 1;
  for(int i=0;i<H-1;++i) {
    for(int j=0;j<30000;++j) {
      if(DP[i][0][j]>0) {
        DP[i+1][0][j+A[i+1][0]] = 1;
        DP[i+1][0][j-A[i+1][0]] = 1;
      }
    }
  }
  for(int i=0;i<W-1;++i) {
    for(int j=0;j<30000;++j) {
      if(DP[0][i][j]>0) {
        DP[0][i+1][j+A[0][i+1]] = 1;
        DP[0][i+1][j-A[0][i+1]] = 1;
      }
    }
  }
  for(int i=1;i<H;++i) {
    for(int j=1;j<W;++j) {
      for(int k=0;k<30000;++k) {
        if(DP[i-1][j][k]>0) {
          DP[i][j][k+A[i][j]] = 1;
          DP[i][j][k-A[i][j]] = 1;
        }
        if(DP[i][j-1][k]>0) {
          DP[i][j][k+A[i][j]] = 1;
          DP[i][j][k-A[i][j]] = 1;
        }
      }
    }
  }
  int ans = inf;
  for(int i=0;i<30000;++i) {
    if(DP[H-1][W-1][i]>0) ans = min(ans, abs(i-15000));
  }
  cout<<ans<<endl;
}

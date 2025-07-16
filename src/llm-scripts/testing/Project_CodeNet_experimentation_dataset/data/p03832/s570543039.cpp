#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
const ll MOD = 1000000007;
const int SIZE = 1010;
ll inv[SIZE],fac[SIZE],finv[SIZE];
void make(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<SIZE;i++){
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        fac[i]=fac[i-1]*(ll) i%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll Combination (int a,int b) {
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
ll dp[1010][1010];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  make();
  FOR(i,0,1010) dp[i][0] = 1;
  FOR(i,a,b+1) {
    FOR(j,0,n+1) {
      if(dp[i][j] == 0) continue;
      if(j != 0) (dp[i+1][j] += dp[i][j]) %= MOD;
      ll p = 1;
      for(int k = 1; k <= d && j + i * k <= n; k++) {
        p = (((p * Combination(n - j - i * (k - 1), i) % MOD) * inv[k]) % MOD) % MOD;
        if(k >= c) (dp[i+1][j+i*k] += (dp[i][j] * p) % MOD) %= MOD;
      }
    }
  }
  cout << dp[b+1][n] << endl;
  return 0;
}
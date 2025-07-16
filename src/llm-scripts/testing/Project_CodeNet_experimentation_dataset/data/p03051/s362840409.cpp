#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <float.h>
#include <random>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge] << '\n'
#define debugArrayP(x,n) for(long long hoge = 0; (hoge) < (n); ++ (hoge)) cerr << #x << "[" << hoge << "]: " << x[hoge].first<< " " << x[hoge].second << '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

ll mod_pow(ll x,int n){
  return n? n&1? x*mod_pow(x,n-1)%MOD:mod_pow(x*x%MOD,n/2):1;
}

int N;
ll dp[(1<<20)+10],dpsum[(1<<20)+10],dpsum2[(1<<20)+10];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>N;
  vint A(N);
  repeat(i,N)cin>>A[i];
  int c=0;
  int xorsum=0;
  repeat(i,N){
    c++;
    int j=i+1;
    xorsum=A[i];
    while(j<N&&xorsum!=0){
      dp[xorsum] = (1+dpsum[xorsum]*c-dpsum2[xorsum]+MOD)%MOD;
      dpsum[xorsum] = (dpsum[xorsum]+dp[xorsum])%MOD;
      dpsum2[xorsum] = (dpsum2[xorsum]+dp[xorsum]*c)%MOD;
      xorsum ^= A[j];
      j++;
    }
    i=j-1;
  }
  ll ans = 0;
  if(xorsum){
    ans = (1+dpsum[xorsum]*c-dpsum2[xorsum]+MOD)%MOD;
  }else{
    ans = mod_pow(2,c-1);
    repeat(i,1<<20){
      ans = (ans+dpsum[i])%MOD;
    }
  }
  cout<<ans<<endl;
  return 0;
}

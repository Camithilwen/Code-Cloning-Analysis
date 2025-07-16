#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second

#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'

using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e5+5, LG = 17, MOD = 1e9+7;
const int SQ = 320;
const long double EPS = 1e-7;
int a[N];
int F[N<<1], iF[N<<1];
int n;
int fast(int b, int e){
  int res = 1;
  for(;e;b=1ll*b*b%MOD,e>>=1)
    if(e&1)res = 1ll * res * b % MOD;
  return res;
}
void init(){
  F[0] = iF[0] = 1;
  f(i,1,N<<1){
    F[i] = 1ll * i * F[i-1] % MOD;
    iF[i] = fast(F[i], MOD - 2);
  }
}
int get(int x1, int y1, int x2, int y2){
  int cntX = x2 - x1;
  int cntY = y2 - y1;
  return 1ll *F[cntX+cntY] * iF[cntX] % MOD * iF[cntY] % MOD;
}
int32_t main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE
  init();
  int H,W,A,B;
  cin>>H>>W>>A>>B;
  int ans = 0;
  f(i,1,H-A+1){
    int x = get(1,1,i,B+1);
    if(i>1)x-=get(1,1,i-1,B+1);
    if(x<0)x+=MOD;
    ans += 1ll * x *get(i,B+1,H,W) % MOD;
    if(ans>=MOD)ans-=MOD;
  }
  cout<<ans<<endl;
  return 0;
}

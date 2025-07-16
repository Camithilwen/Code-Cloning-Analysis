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

const int N = 1e5+5, LG = 17, MOD = 998244353;
const int SQ = 390;
const long double EPS = 1e-7;
int n, x[N], L;
int tb[N][17];
int32_t main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE
  cin >> n;
  f(i,0,n){
    cin >> x[i];
  }
  cin >> L;
  for(int i = 0, j = 0; i < n; i++){
    while(j<n&&x[j]-x[i]<=L)j++;
    tb[i][0] = j - 1;
  }

  f(k,1,17)
    for(int i = 0; i <n; i++)
      tb[i][k] = tb[tb[i][k-1]][k-1];

  int q; cin >> q;
  while(q--){
    int x, y; cin >> x >> y;  --x,--y;
    if(x>y)swap(x,y);
    int ans = 0;
    for(int k = 16; k >= 0; --k)
    if(tb[x][k] < y){
      x = tb[x][k];
      ans += (1 << k);
    }
    cout <<ans+1<<'\n';
  }

  return 0;
}

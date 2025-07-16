///not today

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef pair<long long, long long> pll;

#define SZ(x) (int)(x).size()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define int long long
#define accept_sho ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define lc (v << 1)
#define rc ((v << 1)| 1)
#define MID ((R + L) >> 1)

const int mod = 998244353, maxn = 1e6 + 3;
int fc[maxn];

int pw(int a, int b){
      int ans = 1;
      for(int i = 30; i >= 0; i --){
            ans *= ans;                                                    ans %= mod;
            if(b & (1 << i)){
                  ans *= a;                                                ans %= mod;
            }
      }
      return ans;
}

int c(int k, int n){
      if(k == 0){
            return 1;
      }
      if(k > n){
            return 0;
      }
      int ans = fc[n];
      ans *= pw(fc[k], mod - 2);                                           ans %= mod;
      ans *= pw(fc[n - k], mod - 2);                                       ans %= mod;
      return ans;
}

int32_t main(){
      accept_sho
      int n, m;
      cin >>n >>m;
      fc[0] = 1;
      for(int i = 1; i < maxn - 1; i ++){
            fc[i] = fc[i - 1] * i;                                         fc[i] %= mod;
      }
      int ans = max(n, m);
      for(int i = 1; i <= min(n, m); i ++){
            int x = ( c(n - i, n + m - (2 * i)) * c(i, 2 * i) )% mod;
            x *= pw(c(n, n + m) ,mod - 2);                                 x %= mod;
            x *= pw(2, mod - 2);                                           x %= mod;
            ans = (ans + x)% mod;
      }
      cout <<ans <<endl;
      return false;
}

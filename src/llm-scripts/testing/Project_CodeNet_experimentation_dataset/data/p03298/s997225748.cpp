#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include <functional>
using namespace std;
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define MOD (long long int)(1e15+7)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0個の丸と-1個の棒みたいな時に時に効く？不安.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  if(n <= 1e7){
    ret *= kaijo(n); ret %= MOD;
    ret *= gyaku_kaijo(r); ret %= MOD;
    ret *= gyaku_kaijo(n-r); ret %= MOD;
  }else{
    rep(i,r){
      ret *= n-i; ret %= MOD;
      ret *= mpow(r-i, MOD-2); ret %= MOD;
    }
  }
  return ret;
}

int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  ll n;cin>>n;
  string s="", t="", inp; cin>>inp;
  rep(i,n){
    s += inp[i];
    t += inp[2*n-1-i];
  }

  ll ans = 0;
  rep(bit, 1<<n){
    bitset<18> bs(bit);
    string x = "", y = "";
    rep(i,n){
      if(bs[i]){
        x += s[i];
      }else{
        y += s[i];
      }
    }
    rep(i,n){
      x += "X";
      y += "X";
    }
    ll dp[20][20] = {};
    dp[0][0] = 1;
    rep(i,n){
      rep(j,n+1){
        if(x[j] == t[i]){
          dp[i+1][j+1] += dp[i][j];
          dp[i+1][j+1] %= MOD;
        }
        if(i-j < 0) continue;
        if(y[(i-j)] == t[i]){
          dp[i+1][j] += dp[i][j];
          dp[i+1][j] %= MOD;
        }
      }
    }
    ans += dp[n][bs.count()];
    /*if(dp[n][bs.count()] > 0 bit == 9){
      rep(i,n){
        cout<<bs[i];
      }
      cout<<endl;
      cout<<x<<" "<<y<<endl;

      cout<<dp[2][0]<<" "<<x[0]<<" "<<t[2]<<endl;
    }*/
    ans %= MOD;
  }
  cout<<ans<<endl;
}
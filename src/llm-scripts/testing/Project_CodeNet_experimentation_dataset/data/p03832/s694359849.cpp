#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

int nextInt() { int x; scanf("%d", &x); return x;}

ll MOD = (ll)(1e9 + 7);

const int MAX_N = 1010;

const int SZ = 312345;

ll inv[SZ];
ll fact[SZ];
ll fact_inv[SZ];
ll choose(int n, int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;
}

ll mod_pow(ll a, ll b, ll p) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

ll f(int m, int k) {
  ll res = fact[m*k];
  (res *= mod_pow(fact_inv[m], k, MOD)) %= MOD;
  (res *= fact_inv[k]) %= MOD;
  return res;
}

ll A, B, C, D;
ll dp[MAX_N][MAX_N];

ll rec(int n, int m) {
  if (n < 0) return 0;
  if (m == 0 && n == 0) return 1;
  if (m == 0 && n > 0) return 0;
  if (dp[n][m] != -1) return dp[n][m];
  ll res = rec(n, m-1);
  if (A <= m && m <= B) {
    for (int k = C; k <= D; k++) {
      if (n - k*m < 0) break;
      ll cur = rec(n - k*m, m-1);
      (cur *= choose(n, k*m)) %= MOD;
      (cur *= f(m, k)) %= MOD;
      res += cur;
    }
  }
  res %= MOD;
  return dp[n][m] = res;
}

int main2() {
  CLR(dp, -1);
  int N = nextInt();
  A = nextInt();
  B = nextInt();
  C = nextInt();
  D = nextInt();
  ll ans = rec(N, N);
  cout << ans << endl;
  return 0;
}

int main() {
  {
    inv[1] = 1;
    for (int i = 2; i < SZ; i++) inv[i] = inv[(int) (MOD % i)] * (MOD - MOD / i) % MOD;
    fact[0] = 1;
    for (int i = 1; i < SZ; i++) fact[i] = fact[i-1] * i % MOD;
    fact_inv[0] = 1;
    for (int i = 1; i < SZ; i++) fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
  }
#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
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

ll nextLong() { ll x; scanf("%lld", &x); return x;}

ll rev(ll n) {
  ll res = 0;
  while (n > 0) {
    int r = n % 10;
    res = res * 10 + r;
    n /= 10;
  }
  return res;
}

bool check(ll N, ll D) {
  return rev(N) == N + D;
}

ll ways0(int m) {
  if (m < 0) return 0;
  return 9-m;
}

ll ways(int m) {
  return 10-abs(m);
}

ll ten[20];
ll total = 0;
void rec(ll L, ll R, ll D, ll curr) {
  if (curr == 0) return;

  if (L == R) {
    if (D == 0) {
      total += curr * 10;
    }
    return;
  }
  if (L < R) {
    if (D == 0) {
      total += curr;
    }
    return;
  }

  ll C = ten[L] - ten[R];
  if (D < -C*10 || C*10 < D) return;
  if (R == 0) {
    for (int a = 0; a <= 9; a++) {
      rec(L-1, R+1, D - (ten[L]-ten[R]) * a, curr * ways0(a));
    }

  } else {
    for (int a = -9; a <= 9; a++) {
      rec(L-1, R+1, D - (ten[L]-ten[R]) * a, curr * ways(a));
    }
  }
}

ll solve(ll D, ll k) {
  if (k <= 6) {
    ll res = 0;
    for (int n = ten[k-1]; n < ten[k]; n++) {
      if (check(n, D)) ++res;
    }
    return res;
  }
  total = 0;
  rec(k-1, 0, D, 1);
  return total;

}

int main2() {
  ll D = nextLong();
  ll ans = 0;
  for (int k = 1; k <= 18; k++) {
    ans += solve(D, k);
  }
  cout << ans << endl;
  return 0;
}

int main() {

  ten[0] = 1;
  for (int i = 1; i < 20; i++) ten[i] = ten[i-1] * 10;

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}

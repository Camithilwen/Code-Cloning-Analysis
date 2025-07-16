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


ll ten[20];

ll val = 0;
void f(int L, int R, ll D, ll cur) {
  if (L > R) {
    if (D == 0) val += cur;
    return;
  }

  if (abs(D) > ten[R+1]) return;
  // cout << L << " " << R << " " << D << endl;

  if (L == R) {
    f(L+1, R-1, D, cur * 10);
  } else {

    for (int d = -9; d <= 9; d++) {
      ll D2 = D - (ten[R] - ten[L]) * d;
      ll ways = 10 - abs(d);
      if (L == 0) ways = 9 - abs(d);
      f(L+1, R-1, D2, cur * ways);
    }
  }

}

int main2() {
  ll D = nextLong();

  ten[0] = 1;
  REP(i, 19) ten[i+1] = ten[i] * 10;

  ll ans = 0;
  for (int k = 1; k <= 18; k++) {
    val = 0;
    f(0, k-1, D, 1);
    ans += val;
  }
  cout << ans << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
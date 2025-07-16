#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

ll nextLong() { ll x; scanf("%lld", &x); return x;}


int main2() {
  int N = nextLong();
  int Q = nextLong();
  fenwick_tree<ll> fw(N+10);
  REP(i, N) {
    int x = nextLong();
    fw.add(i, x);
  }
  REP(qqq, Q) {
    int t = nextLong();
    if (t == 0) {
      int p = nextLong();
      int x = nextLong();
      fw.add(p, x);
    }
    else
    {
      int l = nextLong();
      int r = nextLong();
      ll ans = fw.sum(l, r);
      cout << ans << '\n';
    }
  }

  
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
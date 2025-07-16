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

const int MAX_N = 212345;
vector<pair<int,int>> g[MAX_N];

ll dist[MAX_N];

void dfs(int u, int prev, ll cur_dist) {
  dist[u] = cur_dist;
  for (auto e : g[u]) if (e.first != prev) {
    dfs(e.first, u, cur_dist + e.second);
  }
}
int main2() {
  REP(i, MAX_N) g[i].clear();
  int N = nextLong();

  REP(i, N-1) {
    int a = nextLong() - 1;
    int b = nextLong() - 1;
    ll c = nextLong();
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  int Q = nextLong();
  int K = nextLong() - 1;
  dfs(K, -1, 0);
  REP(_, Q) {
    int x = nextLong() - 1;
    int y = nextLong() - 1;
    ll ans = dist[x] + dist[y];
    cout << ans << '\n';
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
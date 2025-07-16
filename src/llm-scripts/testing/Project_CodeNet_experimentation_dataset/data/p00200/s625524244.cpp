#include <bits/stdc++.h>
using namespace std;

#define iota(i,n,b,s) for(int i=int(b);i!=int((b)+(s)*(n));i+=(s))
#define range(i,n,m) iota(i,(((n)>(m))?((n)-(m)+1):((m)-(n)+1)),(n),((n)>(m)?-1:1))
#define rep(i,n) iota(i,(n),0,1)

#define INF (1e9)
#define EPS (1e-9)
#define cons(a,b) (make_pair(a,b))
#define car(a) (a.first)
#define cdr(a) (a.second)
#define cadr(a) (car(cdr(a)))
#define cddr(a) (cdr(cdr(a)))
#define all(a) a.begin(), a.end()
#define trace(var) cerr<<">>> "<<#var<<" = "<<var<<endl;

typedef long long INTEGER;
typedef double FLOAT;

template<class S, class T>
ostream& operator<<(ostream& os, pair<S,T> p) {
  os << '(' << car(p) << ", " << cdr(p) << ')';
  return os;
}

template<class T>
ostream& operator<<(ostream& os, vector<T> v) {
  os << v[0];
  for (int i=1, len=v.size(); i<len; ++i) os << ' ' << v[i];
  return os;
}

const int MM = 100;
int cost[MM][MM];
int toki[MM][MM];

int main() {

entry:;
  int n, m; cin >> m >> n;
  if (n + m == 0) return 0;

  rep (i, n) {
    rep (j, n) {
      cost[i][j] = INF;
      toki[i][j] = INF;
    }
    cost[i][i] = 0;
    toki[i][i] = 0;
  }

  rep (i, m) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    --a; --b;
    cost[a][b] = cost[b][a] = c;
    toki[a][b] = toki[b][a] = t;
  }

  rep (k, n) {
    rep (i, n) {
      rep (j, n) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        toki[i][j] = min(toki[i][j], toki[i][k] + toki[k][j]);
      }
    }
  }

  //rep (i,n) { rep(j,n) { cout << cost[i][j] << ' '; } cout << endl; }

  int k; cin >> k;
  rep (i, k) {
    int a, b, t;
    cin >> a >> b >> t;
    --a; --b;
    if (t) {
      cout << toki[a][b] << endl;
    } else {
      cout << cost[a][b] << endl;
    }
  }

  goto entry;

  return 0;
}
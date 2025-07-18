#include <bits/stdc++.h>
using namespace std;

#define iota(i,n,b,s) for(int i=int(b);i!=int((b)+(s)*(n));i+=(s))
#define range(i,n,m) iota(i,(((n)>(m))?((n)-(m)):((m)-(n))),(n),((n)>(m)?-1:1))
#define rep(i,n) iota(i,(n),0,1)
#define loop for(;;)

#define INF (1e9)
#define EPS (1e-9)
#define cons(a,b) (make_pair(a,b))
#define car(a) (a.first)
#define cdr(a) (a.second)
#define cadr(a) (car(cdr(a)))
#define cddr(a) (cdr(cdr(a)))
#define all(a) a.begin(), a.end()
#define trace(var) cerr<<">>> "<<#var<<" = "<<var<<endl;

typedef long long Integer;
typedef double Real;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<string,int> Dictionary;
const Real PI = acos(-1);

template<class S, class T>
ostream& operator<<(ostream& os, pair<S,T> p) {
  os << '(' << car(p) << ", " << cdr(p) << ')';
  return os;
}

template<class T>
ostream& operator<<(ostream& os, vector<T> v) {
  if (v.size() == 0) {
    os << "(empty)";
    return os;
  }
  os << v[0];
  for (int i=1, len=v.size(); i<len; ++i) os << ' ' << v[i];
  return os;
}

int dx[] = { -1, 0, 1, 0 };
int dy[] = {  0, -1, 0, 1 };

bool
f(vector<int>&ln, int idx, int x, int y) {
  if (idx == 10) return true;
  int z = ln[idx];
  return (x < z && f(ln, idx + 1, z, y)) || (y < z && f(ln, idx + 1, x, z));
}

int main() {

  loop {
    vector<int>ls(10);
    char com;
    int v1, v2;

    int len = 0;
    rep(i, 10) {
      cin >> ls[i] >> com;
      len += ls[i];
    }
    if (!cin) break;

    cin >> v1 >> com >> v2;
    int V = v1 + v2;

    rep (i, 10) {
      ls[i] *= V;
    }

    int le1 = len * v1;
    for (int i=0; i<10; ++i) {
      le1 -= ls[i];
      if (le1 <= 0) {
        cout << -~i << endl;
        break;
      }
    }

  }

  return 0;
}
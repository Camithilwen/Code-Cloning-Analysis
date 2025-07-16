#include <bits/stdc++.h>
#define rep(i,n)    for(long long i = 0; i < (n) ; ++i)
#define orep(i,n)   for(long long i = 1; i <= (n); ++i)   // one rep
#define drep(i,n)   for(long long i = (n)-1; i >= 0; --i) // down rep
#define srep(i,s,t) for(long long i = (s); i < (t); ++i)  // set rep
#define rng(x)  (x).begin(),(x).end()

  // range
#define rrng(a) (a).rbegin(),(a).rend() // reverse range
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define ru(x,y) (((x)+(y)-1)/(y)) // round up
#define fi first
#define se second
#define eb emplace_back
#define fcout cout << fixed << setprecision(15)


using namespace std;
using ll  = long long;
using P   = pair<int,int>;
using vi  = vector<int>;
using vvi = vector<vi>;
using vp  = vector<P>;
using vl  = vector<ll>;

template<typename T> void Yes(T flag) {
  cout << (flag ? "Yes" : "No") << endl;
}

template<typename T> void pv(vector<T> vec) {
  cout << "[";
  for(auto& v : vec) { cout << v << ","; }
  cout << "]" << endl;
}

template<>
void pv(vector<P> vec) {
  cout << "[";
  for(auto& v : vec) {
    cout << "<" << v.fi << ","<< v.se << ">" << ",";
  }
  cout << "]" << endl;
}

template<typename T> void pv2(vector<vector<T>> vec) {
  for(auto& v : vec) pv(v);
}

int n;
vvi maze;
vi seen;
vi dTaka;
vi dAo;

void dfs(int x,int length,vi &d) {
  int sz = maze.at(x).size();
  seen.at(x) = 1;
  d.at(x) = min(length,d.at(x));
  rep(i,sz) {
    int nx = maze.at(x).at(i);
    if(!seen.at(nx)) dfs(nx,length+1,d);
  }
}
const int INF = 100100101;

int main() {

  cin >> n;
  int taka,ao;cin >> taka >> ao;
  taka--;ao--;
  maze = vvi(n,vi());

  int m = n-1;
  rep(i,m) {
    int a,b;cin >> a >> b;
    a--;b--;
    maze.at(a).eb(b);
    maze.at(b).eb(a);
  }

seen = vi(n,0);
  dTaka = vi(n,INF);
  dfs(taka,0,dTaka);
  seen = vi(n,0);
  dAo = vi(n,INF);
  dfs(ao,0,dAo);

  int ans = 0;
  rep(i,n) {
    if(dTaka.at(i) < dAo.at(i)) ans = max(ans,dAo.at(i)-1);
  }

  cout << ans << endl;


  return 0;
}

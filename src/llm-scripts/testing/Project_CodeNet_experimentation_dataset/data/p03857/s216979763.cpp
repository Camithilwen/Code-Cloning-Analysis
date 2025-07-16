#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define YY cout << "Yes" << endl;
#define NN cout << "No" << endl;
#define ve vector
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
// *max_element(all(d))
class UnionFind{
  private:
    vector<int>par;
  public:
    UnionFind(int n):par(n,-1){}
    int root(int x){
      if(par[x] < 0)return x;
      return par[x] = root(par[x]);
    }
    bool unite(int x,int y){
      x = root(x); y = root(y);
      if (x == y) return false;
      if (par[x] > par[y]) swap(x, y);
      par[x] += par[y];
      par[y] = x;
      return true;
    }
    bool same(int x,int y){
      return root(x) == root(y);
    }
    int size(int x) {
      return -par[root(x)];
    }
};
int solve(){
  int n,k,l;
  cin >> n >> k >> l;
  UnionFind uf(n),uf2(n);
  rep(i,k){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a,b);
  }
  rep(i,l){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    uf2.unite(a,b);
  }
  map<pair<int,int>,int>m;
  rep(i,n){
    pair<int,int>P;
    P.first = uf.root(i);
    P.second = uf2.root(i);
    m[P]++;
  }
  rep(i,n){
    pair<int,int>P;
    P.first = uf.root(i);
    P.second = uf2.root(i);
    cout << m[P] << " ";
  }
  cout << endl;
  return 0; 
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  cout << fixed;cout << setprecision(16);
  solve();
  return 0;
}
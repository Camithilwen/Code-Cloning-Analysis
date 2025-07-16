#include <bits/stdc++.h>
using namespace std ;

#define pb(n) push_back(n)
#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define gsort(st,en) sort((st),(en),greater<int>())
#define vmax(ary) *max_element(all(ary))
#define vmin(ary) *min_element(all(ary))
#define debug(x) cout<<#x<<": "<<x<<endl
#define fcout(n) cout<<fixed<<setprecision((n))
#define scout(n) cout<<setw(n)
#define vary(type,name,size,init) vector< type> name(size,init)

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define REP(i,a,b) for(int i = (a);i < (int)(b);++i)
#define repi(it,array) for(auto it = array.begin(),end = array.end(); it != end;++it)
#define repa(n,array) for(auto &n :(array))

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using dict = map<string,int>;
using pii = pair<int,int> ;
using pll = pair<ll,ll> ;

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

struct Person{
  ll id,d;
  vector<ll> friends;
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  while(cin >> n >> m && n && m){
    vector<ll> p[n+1];
    ll a, b;
    rep(i,m){
      cin >> a >> b;
      p[a].pb(b);
      p[b].pb(a);
    }
    set<ll> s;
    s.insert(1);
    rep(i,p[1].size()){
      s.insert(p[1][i]);
      for(auto N : p[p[1][i]]){
        s.insert(N);
      }
    }
    cout << s.size()-1<<endl;
  }
  return 0;
}
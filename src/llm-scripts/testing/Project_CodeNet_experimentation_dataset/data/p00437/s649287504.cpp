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
#define vvl(v,w,h,init) vector<vector<ll>> v(w,vector<ll>(h,init));

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
const int dy[] = {-1,0,1,0,1,-1,1,-1};
const int dx[] = {0,-1,0,1,1,-1,-1,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}

struct data{
  ll i,j,k;
  vector<ll> v;
  ll ooo(set<ll> ok){
    ll cnt = 0,part,flag = 0;
    v.resize(3);
    v[0] = i;
    v[1] = j;
    v[2] = k;
    for(auto n:ok){
      rep(i,3){
        if(v[i] == n){
          flag |= (1 << i);
          ++cnt;
        }
      }
    }
    if(cnt == 2){
      rep(i,3){
        if(!(flag & (1 << i))){
          return v[i];
        }
      }
    }
    return -1;
  }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a,b,c;
  while(cin >> a >> b >> c && a && b && c){
    ll n;
    set<ll> ok;
    set<ll> wrong;
    vector<data> qes;
    cin >> n;
    ll x,y,z,w;
    rep(i,n){
      cin >> x >> y >> z >> w;
      --x,--y,--z;
      if(w == 1){
        ok.insert(x);
        ok.insert(z);
        ok.insert(y);
      }
      else{
        qes.push_back({x,y,z});
      }
    }
    rep(i,qes.size()){
      wrong.insert(qes[i].ooo(ok));
    }
    rep(i,a+b+c){
      if(find(all(ok),i) != ok.end()){
        cout << 1<<endl;
      }
      else if(find(all(wrong),i) != wrong.end()){
        cout << 0 <<endl;
      }
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
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

const int mod = 1000000007;
constexpr int imax = ((1<<30)-1)*2+1 ;
constexpr int inf = 100000000;
constexpr double PI = acos(-1.0) ;
double eps = 1e-10 ;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

inline bool value(int x,int y,int w,int h){
  return (x >= 0 && x < w && y >= 0 && y < h);
}
ll N,m;
vector<vector<ll>> warshall_floyd(vector<vector<ll>> d){
  rep(k,m){
    rep(i,m){
      rep(j,m){
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  while(cin>>N>>m&&N&&m){
    int a,b,c,d;
    vector<vector<ll>> time(m+1,vector<ll>(m+1,inf));
    vector<vector<ll>> cost(m+1,vector<ll>(m+1,inf));
    ++m;
    rep(i,N){
      cin >> a >> b >> c >> d;
      time[a][b] = d;
      cost[a][b] = c;
      time[b][a] = d;
      cost[b][a] = c;
    }
    int k,p,q,r ;
    auto T = warshall_floyd(time);
    auto C = warshall_floyd(cost);
    cin >> k;
    rep(i,k){
      cin >> p >> q >> r;
      if(r){
        cout << T[p][q]<<endl;
      }
      else{
        cout << C[p][q]<<endl;
      }
    }
  }
  return 0;
}
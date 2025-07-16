#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9+10;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

const ll dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const ll dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(ll y, ll x, ll H, ll W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

char G[405][405];

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll h,w; cin>>h>>w;
  rep(i,h) rep(j,w) cin>>G[i][j];
  map<char, int> ctoi;
  ctoi['.']=0, ctoi['#']=1;
  
  ll ans=0;
  
  
  vvi visited(h+1, vi(w+1));
  
  rep(i,h){
    rep(j,w){
      if(visited[i][j]) continue;
      visited[i][j]=1;
      
      char st=ctoi[G[i][j]];
      
      ll cnt0=0, cnt1=0;
      if(st) cnt1++;
      else cnt0++;
      
      queue<pair<pii,int>> q;
      q.emplace(pii(i,j), st);
      
      ll tmp=0;
      
      while(!q.empty()){
        auto p=q.front(); q.pop();
        int y=p.first.first, x=p.first.second, from=p.second;
        rep(ki,4){
          int ny=y+dy[ki], nx=x+dx[ki];
          if(inside(ny,nx,h,w)){
            if(visited[ny][nx]) continue;
            ll now=ctoi[G[ny][nx]];
            if(from==now) continue;
            visited[ny][nx]=1;
            q.emplace(pii(ny,nx), now);
            if(now) cnt1++;
            else cnt0++;
          }
        }
      }
      
      ans+=cnt1*cnt0;
    }
  }
  
  cout<<ans<<endl;
  
}
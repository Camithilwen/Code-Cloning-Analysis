#include <bits/stdc++.h>
#include<cmath>
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

vector<string> Split(char c,string s){
  vector<string> res(0);
  string str = "";
  rep(i,s.size()){
    if(s[i] == c){
      res.push_back(str);
      str.clear();
    }
    else{
      str += s[i];
    }
  }
  res.push_back(str);
  return res;
}
template<typename T>
T ston(string& str, T n){
  istringstream sin(str) ;
  T num ;
  sin >> num ;
  return num ;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;
  while(cin >> n >> m && n && m){
    vector<ll> v(101);
    ll k,tmp;
    rep(i,n){
      cin >> k;
      rep(j,k){
        cin >> tmp;
        v[tmp]++;
      }
    }
    ll ans = 0,cnt = m-1;
    rep(i,101){
      if(v[i] >= cnt){
        if(v[i] > cnt)
          ans = i;
        cnt = v[i];
      }
    }
    if(ans) cout << ans << endl;
    else cout << 0 << endl;
  }
  return 0;
}
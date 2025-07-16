#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int x,y;
  cin >> x >> y;

  int ans=0;
  if(x==y)  ans=0;
  else if(x==0){
    if(y<0) ans++;
    ans+=abs(y);
  }
  else if(y==0){
    if(x>0) ans++;
    ans+=abs(x);
  }
  else if(x<y){
    if(x<0 && 0<y) ans=1+abs(y-abs(x));
    else  ans=abs(y-x);
  }
  else if(y<x){
    if(0<y){
      ans++;
      ans+=1+abs(y-abs(x));
    }
    else if(y<0 && 0<x){
      ans++;
      ans+=abs(abs(y)-x);
    }
    else if(x<0){
      ans++;
      x=-x;
      ans++;
      ans+=abs(abs(y)-x);
    }
  }
  cout << ans << endl;

  return 0;
}
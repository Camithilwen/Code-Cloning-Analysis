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
  int H,W;
  cin >> H >> W;
  vector<vector<int>> A(H,vector<int>(W));
  rep(i,H){
    rep(j,W)  cin >> A.at(i).at(j);
  }
  vector<vector<int>> B(H,vector<int>(W));
  rep(i,H){
    rep(j,W)  cin >> B.at(i).at(j);
  }

  int base=100*(H+W);
  vector<vector<vector<bool>>> dp(H,vector<vector<bool>>(W,vector<bool>(2*base,false)));
  dp.at(0).at(0).at(base+A.at(0).at(0)-B.at(0).at(0))=true;
  dp.at(0).at(0).at(base-A.at(0).at(0)+B.at(0).at(0))=true;
  rep(i,H){
    rep(j,W){
      int tmp=A.at(i).at(j)-B.at(i).at(j);
      rep(k,2*base){
        if(i-1>=0 && dp.at(i-1).at(j).at(k)){
          if(k+tmp <2*base) dp.at(i).at(j).at(k+tmp)=true;
          if(k-tmp >=0) dp.at(i).at(j).at(k-tmp)=true;
        }
        if(j-1>=0 && dp.at(i).at(j-1).at(k)){
          if(k+tmp <2*base) dp.at(i).at(j).at(k+tmp)=true;
          if(k-tmp >=0) dp.at(i).at(j).at(k-tmp)=true;
        }
      }
    }
  }
  int ans=1e9;
  rep(i,2*base){
    if(!dp.at(H-1).at(W-1).at(i))  continue;
    chmin(ans,abs(i-base));
  }
  cout << ans << endl;

  return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#include <stack>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

int H,W;
vector<string> S;

int same[2020][2020];
int diff[2020][2020];

void preprocess(){
    rep(i,H) rep(j,W){
        if(j==0) continue;
        if(S[i][j]==S[i][j-1]) same[i][j]=1;
        if(i>0&&S[i][j]==S[i][j-1]) same[i][j]+=same[i-1][j];
    }
    rep(i,H) rep(j,W){
        if(j==0) continue;
        if(S[i][j]!=S[i][j-1]) diff[i][j]=1;
        if(i>0&&S[i][j]!=S[i][j-1]) diff[i][j]+=diff[i-1][j];
    }
}

int calc(vector<int> &P){
    stack<pair<int,int>> st;
    int res=0;
    rep(j,W){
        if(j==0) continue;
        int pos=j;
        while(st.size()&&st.top().first>=P[j]){
            auto f=st.top();
            st.pop();
            pos=f.second;
            chmax(res,f.first*(j-pos+1));
        }
        st.push(mkp(P[j],pos));
    }
    while(st.size()){
        auto f=st.top();
        st.pop();
        chmax(res,f.first*(W+1-f.second));
    }

    return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>H>>W;
  S.resize(H);
  rep(i,H) cin>>S[i];

  preprocess();

  int ans=max(H,W);
  rep(i,H){
      if(i==0) continue;
      {
          vector<int> P(W,0);
          vector<int> rev(W,0);
          rep(j,W) if(S[i][j]=='.') rev[j]=1;
          rep(j,W){
              if(j==0) continue;
              if(rev[j]==rev[j-1]) P[j]=same[i][j];
              else P[j]=diff[i][j];
          }
          chmax(ans,calc(P));
      }

      {
          vector<int> P(W,0);
          vector<int> rev(W,0);
          rep(j,W) if(S[i][j]!='.') rev[j]=1;
          rep(j,W){
              if(j==0) continue;
              if(rev[j]==rev[j-1]) P[j]=same[i][j];
              else P[j]=diff[i][j];
          }
          chmax(ans,calc(P));
      }
  }

  cout<<ans<<endl;

  return 0;
}

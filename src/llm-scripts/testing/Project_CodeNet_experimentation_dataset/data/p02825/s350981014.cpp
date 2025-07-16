#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define REP(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)

#define DEBUG(x) cout<<#x<<": "<<(x)<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";REP(i, v.size())cout<<' '<<v[i];cout<<'\n'
#define ALL(a) (a).begin(), (a).end()

template<typename T> inline void CHMAX(T& a, const T b) {if(a<b) a=b;}
template<typename T> inline void CHMIN(T& a, const T b) {if(a>b) a=b;}

constexpr ll MOD=1000000007ll;
// constexpr ll MOD=998244353ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

const double EPS=1e-11;
#define EQ0(x) (abs((x))<EPS)
#define EQ(a, b) (abs((a)-(b))<EPS)

char ans[1252][1252];
string three[3]={"aa.", "..a", "..a"};
string four[4]={"aabc", "ddbc", "bcaa", "bcdd"};
string five[5]{"aabba", "bcc.a", "b..cb", "a..cb", "abbaa"};
string six[6]={"aabc..", "ddbc..", "..aabc", "..ddbc", "bc..aa", "bc..dd"};
string seven[7]={"aabbcc.", "dd.dd.a", "..d..da", "..d..db", "dd.dd.b", "..d..dc", "..d..dc"};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cout<<setprecision(10)<<fixed;
  int n;
  cin>>n;
  REP(i, n){
    REP(j, n){
      ans[i][j]='.';
    }
  }
  if(n==2){
    cout<<-1<<'\n';
    return 0;
  }
  int cur=n;
  while(cur>7){
    REP(i, 4){
      REP(j, 4){
        ans[i+n-cur][j+n-cur]=four[i][j];
      }
    }
    cur-=4;
  }
  if(cur==3){
    REP(i, 3){
      REP(j, 3){
        ans[i+n-cur][j+n-cur]=three[i][j];
      }
    }
  }
  else if(cur==4){
    REP(i, 4){
      REP(j, 4){
        ans[i+n-cur][j+n-cur]=four[i][j];
      }
    }
  }
  else if(cur==5){
    REP(i, 5){
      REP(j, 5){
        ans[i+n-cur][j+n-cur]=five[i][j];
      }
    }
  }
  else if(cur==6){
    REP(i, 6){
      REP(j, 6){
        ans[i+n-cur][j+n-cur]=six[i][j];
      }
    }
  }
  else{
    REP(i, 7){
      REP(j, 7){
        ans[i+n-cur][j+n-cur]=seven[i][j];
      }
    }
  }
  REP(i, n){
    REP(j, n){
      cout<<ans[i][j];
    }
    cout<<'\n';
  }
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<double> vd;
typedef vector<vd> vdd;

typedef pair<double, double> pd;
typedef vector<pd> vpd;


#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)
#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)
#define RREP(i,x) RFOR(i, x, 0)
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define debug_print(x...) cerr << "line " << __LINE__ << " : "; debug_print_in(x);

template <typename First>
void debug_print_in(First first){
  cerr << first << endl;
  return;
}

template <typename First, typename... Rest>
void debug_print_in(First first, Rest... rest){
  cerr << first << " ";
  debug_print_in(rest...);
  return;
}

void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

template <typename First>
void OUT(First first){
  cout << first << endl;
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

template<class t, class u> t chmax(t&a,u b){if(a<b)a=b; return a;};
template<class t, class u> t chmin(t&a,u b){if(a>b)a=b; return a;};
int popcount(int t){return __builtin_popcount(t);} //GCC
int popcount(ll t){return __builtin_popcountll(t);} //GCC

template <typename T>
void vec_print(vector<T> VEC){
  REP(i, VEC.size()){
    cerr << VEC[i] << " ";
  }
  cerr << endl;
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  REP(i,MAT.size()){
    REP(j,MAT[i].size()){
      cerr << MAT[i][j] << " ";
    }
    cerr << endl;
  }
};

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;
constexpr ll MOD = (ll)((1E+9)+7);

ll N;
string S;

vll Ms;
vvll dp;

ll search(ll k){
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  REP(i,N){
    if(i-k>=0){
      if(S[i-k]=='D'){
        dp[i][0]--;
        dp[i][1] -= (Ms[i-1]-Ms[i-k]);
      }
    }
    switch(S[i]){
      case 'D':
        dp[i+1][0] = dp[i][0] + 1;
        dp[i+1][1] = dp[i][1];
        dp[i+1][2] = dp[i][2];
        break;
      case 'M':
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1] + dp[i][0];
        dp[i+1][2] = dp[i][2];
        break;
      case 'C':
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        dp[i+1][2] = dp[i][2] + dp[i][1];
        break;
      default:
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
        dp[i+1][2] = dp[i][2];
        break;
    }
  }

  //mat_print(dp);

  return dp[N][2];
}

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  IN(N);
  IN(S);
  Ms.resize(N, 0);
  if(S[0]=='M') Ms[0]++;
  dp.resize(N+1, vll(3, 0));
  FOR(i,1,N){
    Ms[i]=Ms[i-1];
    if(S[i]=='M') Ms[i]++;
  }

  ll Q;
  IN(Q);
  REP(q,Q){
    ll k;
    IN(k);
    OUT(search(k));
  }


  return 0;
}
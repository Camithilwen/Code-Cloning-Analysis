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

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll N;
  IN(N);
  vpll RL(N);
  REP(i,N){
    IN(RL[i].second, RL[i].first);
  }

  sort(ALL(RL));

  vll Lmax(N, RL[0].second);
  REP(i,N-1){
    Lmax[i+1] = max(Lmax[i], RL[i+1].second);
  }

  /*
  REP(i,N){
    debug_print(RL[i].second, RL[i].first);
  }
  */

  ll ans = max(RL[0].first-Lmax[N-2]+1, (ll)0)+(RL[N-1].first-RL[N-1].second)+1;
  ll Lmax_after = RL[N-1].second;
  for(ll i=N-2; i>0; --i){
    ll Lmax1 = Lmax[i-1];
    ll Rmin1 = RL[0].first;
    ll Lmax2 = RL[i].second;
    ll Rmin2 = RL[i].first;

    ll LR1 = max(Rmin1-Lmax1+1, (ll)0);
    ll LR2 = max(Rmin2-Lmax2+1, (ll)0);
    ll LR1_1 = max(Rmin1-max(Lmax_after, Lmax1)+1, (ll)0);
    ll LR2_1 = max(Rmin2-max(Lmax_after, Lmax2)+1, (ll)0);

    ll ans_tmp = max(LR1+LR2_1, LR1_1+LR2);

    chmax(ans, ans_tmp);
    chmax(Lmax_after, Lmax2);
  }

  OUT(ans);

  return 0;
}

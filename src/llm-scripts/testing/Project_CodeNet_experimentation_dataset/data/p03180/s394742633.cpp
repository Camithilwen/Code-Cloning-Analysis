#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll dp[1<<16], score[1<<16];
ll a[16][16];

ll rec(int S){
    if(dp[S] != -1) return dp[S];
    if(S == 0) return dp[S] = 0;

    ll ret = score[S];
    for(int T=S; T>0; T=T-1&S){
        if(S==T) continue;
        chmax(ret, rec(T) + rec(S^T));
    }

    return dp[S] = ret;
}

int main(void){
    int N; cin >> N; REP(i,1<<N) dp[i] = -1;
    REP(i,N)REP(j,N) cin >> a[i][j];

    REP(S,1<<N){
        REP(i,N)FOR(j,i+1,N) if(S>>i & S>>j & 1) score[S] += a[i][j];
    }

    ll ans = rec((1<<N)-1);
    cout << ans << en;
    return 0;
}
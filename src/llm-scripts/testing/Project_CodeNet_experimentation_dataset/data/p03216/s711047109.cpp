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

int main(void){
    int N; cin >> N;
    string S; cin >> S;

    VI nd(N,0), nm(N,0), nc(N,0);
    REP(i,N){
        if(S[i]=='D') nd[i] = 1;
        else if(S[i]=='M') nm[i] = 1;
        else if(S[i]=='C') nc[i] = 1;
    }
    REP(i,N-1) nd[i+1] += nd[i]; REP(i,N-1) nm[i+1] += nm[i]; REP(i,N-1) nc[i+1] += nc[i];
    ll ndmc = 0;
    REP(i,N) if(S[i]=='M') ndmc += (ll)nd[i]*(nc[N-1]-nc[i]);
    VL sc(nc[N-1]+1);
    REP(i,N) if(S[i]=='C') sc[nc[i]] = nm[i];
    REP(i,nc[N-1]) sc[i+1] += sc[i];

    int Q; cin >> Q;
    REP(i,Q){
        int k; cin >> k;
        ll ans = 0;
        REP(i,N-k){
            if(S[i] != 'D') continue;
            ll M = nm[i];
            ll t = nc.back() - nc[i+k-1];
            ans += sc.back() - sc[nc.back()-t] - M*t;
        }
        cout << ndmc - ans << en;
    }
    return 0;
}
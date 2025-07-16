#include "bits/stdc++.h"
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, a, b) for(int i=(b-1);i>=(a);i--)
#define REP(i, n) for(int i=0; i<(n); i++)
#define RREP(i, n) for(int i=(n-1); i>=0; i--)
#define REP1(i, n) for(int i=1; i<=(n); i++)
#define RREP1(i, n) for(int i=(n); i>=1; i--)
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE_SORT(l) sort(ALL(l)); l.erase(unique(ALL(l)), l.end());
#define CONTAIN(a, b) find(ALL(a), (b)) != (a).end()
#define out(...) printf(__VA_ARGS__)
#if DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) /* ... */
#endif
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
void _OUT() {}; template<class H, class... T> void _OUT(H &h, T &... t) { cout<<' '<<h; _OUT(t...); };
template<class H, class... T> void _P(H &h, T &... t) { cout<<h; _OUT(t...); };
#define _PN(...) _P(__VA_ARGS__); cout << endl;
#define EXEC(...) void exec() { (__VA_ARGS__ - 1) ? multi() : solve(0); }

void exec();
void solve(int t);
void multi() { int TT; cin>>TT; REP1(t,TT) solve(t); }
signed main()
{
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    exec();
    return 0;
}

/*================================*/
#if DEBUG
#define SIZE 10
#else
#define SIZE 333
#endif

int N,M;
int A[SIZE][SIZE];

void solve(int _t) {
    cin>>N>>M;
    REP(n,N) {
        REP(m,M) {
            cin>>A[n][m];
            A[n][m]--;
        }
    }
    int ans = INT_MAX;
    vector<int> NG(M,0);
    REP(_,M) {
        vector<int> C(M,0);
        REP(n,N) {
            REP(m,M)if(!NG[A[n][m]]) {
                C[A[n][m]]++;
                break;
            }
        }
        int cnt = 0;
        int mai = -1;
        REP(m,M) if (chmax(cnt, C[m])) mai=m;
        debug("mai:%lld, cnt:%lld\n",mai,cnt);
        chmin(ans,cnt);
        NG[mai]=1;
    }
    _PN(ans);
}
EXEC(1)


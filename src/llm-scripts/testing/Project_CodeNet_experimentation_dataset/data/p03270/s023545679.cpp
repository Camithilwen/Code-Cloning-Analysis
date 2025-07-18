/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 2e3+10;
LL dp1[SIZE][SIZE],dp2[SIZE][SIZE];
void pre(){
    dp1[0][0]=1;
    REPP(i,1,SIZE){
        LL now=0;
        REP(j,SIZE){
            ADD(now,dp1[i-1][j]);
            dp1[i][j]=now;
        }
    }
    dp2[0][0]=1;
    REPP(i,1,SIZE){
        LL now=0;
        REP(j,SIZE){
            ADD(now,dp2[i-1][j]*2);
            dp2[i][j]=now-dp2[i-1][j];
            if(dp2[i][j]<0)dp2[i][j]+=MOD;
        }
    }
}
int main(){
    MOD=998244353;
    pre();
    int K,N;
    R(K,N);
    VL res;
    FOR(i,2,K+1){
        int n2=(i-1)/2;
        int n1=K-n2*2-(1-i%2);
        LL me=0;
        if(i&1){
            FOR(k,0,N)ADD(me,dp1[n1][k]*dp2[n2][N-k]);
        }
        else{
            FOR(k,0,N)ADD(me,dp1[n1][k]*dp2[n2][N-k]);
            FOR(k,0,N-1)ADD(me,dp1[n1][k]*dp2[n2][N-1-k]);
        }
        res.PB(me);
    }
    for(int i=SZ(res)-2;i>=0;i--)res.PB(res[i]);
    for(auto x:res)W(x);
    return 0;
}

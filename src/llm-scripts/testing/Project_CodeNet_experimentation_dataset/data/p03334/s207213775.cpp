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
const int SIZE = 610;
int used[SIZE][SIZE];
int N;
int res[SIZE][SIZE],D;
int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
int v;
void dfs(int x,int y,int b){
    if(b)res[x][y]|=v;
    used[x][y]=1;
    for(int k=0;k*k<=D;k++){
        int tmp=sqrt(D-k*k);
        if(tmp*tmp+k*k==D){
            REP(j,4){
                int nx=x+dx[j]*k;
                int ny=y+dy[j]*tmp;
                if(nx<0||ny<0||nx>=2*N||ny>=2*N) continue;
                if(used[nx][ny])continue;
                dfs(nx,ny,1^b);
            }
        }
    }
}
void fil(int _D,int _v){
    D=_D;
    v=_v;
    MS0(used);
    REP(i,2*N){
        REP(j,2*N){
            if(!used[i][j]){
                dfs(i,j,0);
            }
        }
    }
}
VPII ker[4];
int main(){
    int D1,D2;
    R(N,D1,D2);
    fil(D1,1);
    fil(D2,2);
    REP(i,2*N)REP(j,2*N){
        ker[res[i][j]].PB({i,j});
    }
    REP(i,4){
        if(SZ(ker[i])>=N*N){
            REP(j,N*N){
                W(ker[i][j]);
            }
            return 0;
        }
    }
    return 0;
}

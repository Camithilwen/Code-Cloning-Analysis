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
const int SIZE = 1e6+10;
int N,X;
LL b[SIZE],l[SIZE],u[SIZE];
bool used[SIZE];
int main(){
    R(N,X);
    LL need=0;
    priority_queue<PLL>h0,h1,h2;
    REP(i,N){
        R(b[i],l[i],u[i]);
        need+=b[i]*l[i];
        h0.push({l[i]*b[i]+u[i]*(X-b[i]),i});
    }
    LL an=0;
    while(need>=h0.top().F){
        an+=X;
        used[h0.top().S]=1;
        need-=h0.top().F;
        h0.pop();
    }
    if(need<=0){
        W(an);
        return 0;
    }
    int add_id=h0.top().S;
    LL add_v=l[add_id]*b[add_id]+u[add_id]*(X-b[add_id]);
    LL mi=1e18;
    REP(i,N){
        if(used[i]){
            LL need2=need-add_v+l[i]*b[i]+u[i]*(X-b[i]);
            
            if(l[i]*b[i]>=need2){
                mi=min(mi,(need2+l[i]-1)/l[i]);
            }
            else{
                mi=min(mi,(need2-l[i]*b[i]+u[i]-1)/u[i]+b[i]);
            }
        }
        else{
            if(l[i]*b[i]+u[i]*(X-b[i])<need)continue;
            if(l[i]*b[i]>=need){
                mi=min(mi,(need+l[i]-1)/l[i]);
            }
            else{
                mi=min(mi,(need-l[i]*b[i]+u[i]-1)/u[i]+b[i]);
            }
        }
    }
    an+=mi;
    W(an);
    return 0;
}

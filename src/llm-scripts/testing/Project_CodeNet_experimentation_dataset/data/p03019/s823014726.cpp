#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef long long ll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n, x;
long long tgt = 0;

struct ex {
    int l, r, b;
} exam[110000];

long long score(const ex& a, long long h) {
    long long sc = a.l * 1ll * min(h, (ll)a.b);
    sc += a.r * 1ll * max(0LL, h-a.b);
    return sc;
}

bool check(long long hrs) {
    int full = hrs / x;
    int rem = hrs % x; 

    long long sc = 0;
    rep(i,0,full) sc += score(exam[i], x);
    long long best = sc;

    rep(i,full,n) best = max(best, sc + score(exam[i], rem));
    
    if (full < n) {
        sc += score(exam[full], x);
        rep(i,0,full) best = max(best, sc - score(exam[i], x) + score(exam[i],rem));
    }
    
    return best >= tgt;
}

void solve()
{
    re(n,x);
    rep(i,0,n) re(exam[i].b, exam[i].l, exam[i].r);

    rep(i,0,n) tgt += exam[i].l * 1ll * exam[i].b;

    sort(exam, exam+n, [](const ex& a, const ex& b) {
        return score(a,x) > score(b,x);
    });

    long long st = 0, ed = n*1ll*x;
    while (st < ed) {
        long long md = (st+ed)/2;
        if (check(md)) ed = md;
        else st = md+1;
    } 

    ps(st);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}


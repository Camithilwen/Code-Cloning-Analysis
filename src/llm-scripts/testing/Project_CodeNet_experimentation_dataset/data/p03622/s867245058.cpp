#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 1000005
#define eps 1e-12
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
        out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 998244353;
int N,M;
int fac[MAXN],invfac[MAXN],f[MAXN],v[MAXN],h[MAXN],inv[MAXN];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
int C(int n,int m) {
    if(n < m) return 0;
    return mul(fac[n],mul(invfac[m],invfac[n - m]));
}
int way(int x1,int y1,int x2,int y2) {
    return C(x2 - x1 + y2 - y1,y2 - y1);
}
void update(int &x,int y) {
    x = inc(x,y);
}
int fpow(int x,int c) {
    int res = 1,t = x;
    while(c) {
        if(c & 1) res = mul(res,t);
        t = mul(t,t);
        c >>= 1;
    }
    return res;
}
void Solve() {
    read(N);read(M);
    fac[0] = 1;
    inv[1] = 1;
    for(int i = 1 ; i <= N + M ; ++i) {
        fac[i] = mul(fac[i - 1],i);
        if(i > 1) inv[i] = mul(inv[MOD % i],MOD - MOD / i);
    }
    invfac[N + M] = fpow(fac[N + M],MOD - 2);
    for(int i = N + M - 1 ; i >= 0 ; --i) {
        invfac[i] = mul(invfac[i + 1],i + 1);
    }
    if(M > N) h[0] = 1;
    if(N > M) v[0] = 1;
    for(int i = 1 ; i <= N + M ; ++i) {
        h[i] = h[i - 1];
        int r = min(i - 1,N) - h[i - 1] + 1,c = i - 1 - r + 1;
        if(i <= N && M - (N - r) >= c + 1) ++h[i];
        if(i > N && M - (N - r) <= c) --h[i];
        v[i] = v[i - 1];
        c = min(i - 1,M) - v[i - 1] + 1,r = i - 1 - c + 1;
        if(i <= M && N - (M - c) >= r + 1) ++v[i];
        if(i > M && N - (M - c) <= r) --v[i];
    }
    f[0] = mul(C(N + M, N),max(N,M));
    int valh = 0,valv = 0;
    if(h[0]) valh = C(N + M - 1, M - 1);
    if(v[0]) valv = C(N + M - 1, N - 1);
    for(int i = 1 ; i < N + M ; ++i) {
        f[i] = f[i - 1];
        if(h[i - 1]) f[i] = inc(f[i],MOD - valh);
        if(v[i - 1]) f[i] = inc(f[i],MOD - valv);
        if(!h[i - 1] && h[i]) valh = way(i,0,N,M - 1);
        if(!v[i - 1] && v[i]) valv = way(0,i,N - 1,M);
        int r1 = min(i - 1,N) - h[i - 1] + 1,c1 = i - 1 - r1;
        int r2 = min(i,N) - h[i] + 1,c2 = i - r2;
        if(h[i - 1]) {
            if(r2 > r1) {
                valh = inc(valh, MOD - mul(way(0,0,r1,c1),way(r1,c1 + 1,N,M - 1)));
            }
            else {
                if(r2 >= 1) valh = inc(valh,mul(way(0,0,r2 - 1,c2),way(r2,c2,N,M - 1)));
            }
        }
        c1 = min(i - 1,M) - v[i - 1] + 1,r1 = i - 1 - c1;
        c2 = min(i,M) - v[i] + 1,r2 = i - c2;
        if(v[i - 1]) {
            if(c2 > c1) {
                valv = inc(valv, MOD - mul(way(0,0,r1,c1),way(r1 + 1,c1,N - 1,M)));
            }
            else {
                if(c2 >= 1) valv = inc(valv,mul(way(0,0,r2,c2 - 1),way(r2,c2,N - 1,M)));
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < N + M ; ++i) {
        ans = inc(ans,mul(f[i],inv[N + M - i]));
    }
    ans = mul(ans,fpow(C(N + M,N),MOD - 2));
    out(ans);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
    Solve();
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 200005
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
        res = res * 10 +c - '0';
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
int64 D;

int Len(int64 D) {
    int res = 0;
    while(D) {
        res++;
        D /= 10;
    }
    return res;
}
int64 pw[20];
int64 v[20],d[20];
int up;
int64 dfs(int64 rem,int dep) {
    if(dep == up) return !rem;
    int64 t = rem / v[dep];
    int64 res = 0;
    if(abs(t - 1) <= 9 && abs(rem - (t - 1) * v[dep]) < v[dep]) {
        int c = 0;
        if(t - 1 >= 0 && !dep) c = 1;
        res += (d[t - 1 + 9] - c) * dfs(rem - (t - 1) * v[dep],dep + 1);
    }
    if(abs(t) <= 9 && abs(rem - t * v[dep]) < v[dep]) {
        int c = 0;
        if(t >= 0 && !dep) c = 1;
        res += (d[t + 9] - c) * dfs(rem - t * v[dep],dep + 1);
    }
    if(abs(t + 1) <= 9 && abs(rem - (t + 1) * v[dep]) < v[dep]) {
        int c = 0;
        if(t + 1 >= 0 && !dep) c = 1;
        res += (d[t + 1 + 9] - c) * dfs(rem - (t + 1) * v[dep],dep + 1);
    }
    return res;
}
void Solve() {
    read(D);
    int Ld = Len(D);
    int64 ans = 0;
    pw[0] = 1;
    for(int i = 1 ; i <= 18 ; ++i) pw[i] = pw[i - 1] * 10;
    for(int i = 0 ; i <= 9 ; ++i) {
        for(int j = 0 ; j <= 9 ; ++j) {
            d[i - j + 9]++;
        }
    }
    for(int i = Ld ; i <= 2 * Ld ; ++i) {
        for(int j = 0 ; j <= i / 2 ; ++j) v[j] = pw[i - j - 1] - pw[j];
        up = i / 2;
        int64 tmp = dfs(D,0);
        if(i & 1) tmp *= d[0 + 9];
        ans += tmp;
    }
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

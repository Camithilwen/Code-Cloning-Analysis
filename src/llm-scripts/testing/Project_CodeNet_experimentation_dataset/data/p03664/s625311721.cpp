#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 10005
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
int N,M;
struct node {
    int to,next,val;
}E[1005];
int sumE,head[25],pos[(1 << 15) + 5];
int f[16][(1 << 15) + 5],h[16][(1 << 15) + 5],sum[(1 << 15) + 5];
void add(int u,int v,int c) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    E[sumE].val = c;
    head[u] = sumE;
}
inline int lowbit(int x) {
    return x & (-x);
}
void Init() {
    read(N);read(M);
    int u,v,c;
    for(int i = 1 ; i <= M ; ++i) {
        read(u);read(v);read(c);
        add(u,v,c);add(v,u,c);
        h[u][1 << v - 1] = c;
        h[v][1 << u - 1] = c;
    }
    for(int i = 1 ; i <= N ; ++i) {
        for(int j = 1 ; j < (1 << N) ; ++j) {
            if(lowbit(j) == j) continue;
            h[i][j] = h[i][j - lowbit(j)] + h[i][lowbit(j)];
        }
    }
    for(int i = 1 ; i <= N ; ++i) pos[(1 << i - 1)] = i;
    for(int i = 1 ; i < (1 << N) ; ++i) {
        sum[i] = sum[i - lowbit(i)] + h[pos[lowbit(i)]][i - lowbit(i)];
    }
}
void Solve() {
    for(int i = 1 ; i <= N ; ++i) {
        for(int j = 0 ; j < (1 << N) ; ++j) {
            f[i][j] = -1e9;
        }
    }
    f[1][1] = 0;

    for(int j = 0 ; j < (1 << N - 1) ; ++j) {
        for(int i = 1 ; i <= N ; ++i) {
            int S = j << 1 | 1;
            if(!(S & (1 << i - 1))) continue;
            int L = S ^ (1 << i - 1);
            for(int T = L; T ; T = (T - 1) & L) {
                if(f[i][S ^ T] >= 0)
                    f[i][S] = max(f[i][S],f[i][S ^ T] + sum[T ^ (1 << i - 1)]);
            }
            if(f[i][S] >= 0) {
                for(int k = head[i] ; k ; k = E[k].next) {
                    int v = E[k].to;
                    if(!(S & (1 << v - 1))) {
                        f[v][S ^ (1 << v - 1)] = max(f[v][S ^ (1 << v - 1)],f[i][S] + E[k].val);
                    }
                }
            }
        }
    }
    out(sum[(1 << N) - 1] - f[N][(1 << N) - 1]);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
    Init();
    Solve();
}

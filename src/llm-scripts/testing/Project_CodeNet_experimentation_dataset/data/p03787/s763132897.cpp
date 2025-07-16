#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#define enter putchar('\n')
#define space putchar(' ')
//#define ivorysi
#define pb push_back
#define mo 974711
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define MAXN 200005
#define eps 1e-12
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
	if(c == '-') f = -1;
	c = getchar();
    }
    while(c >= '0' && c <= '9') {
	res = res * 10 - '0' + c;
	c = getchar();
    }
    res = res * f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) out(x / 10);
    putchar('0' + x % 10);
}
int N,M,I,P,Q;
struct node {
    int next,to;
}E[MAXN * 2];
int head[MAXN],sumE,col[MAXN];
bool vis[MAXN];
void dfs(int u) {
    vis[u] = 1;
    for(int i = head[u] ; i ; i = E[i].next) {
	int v = E[i].to;
	if(!vis[v]) {
	    dfs(v);
	}
    }
}
bool paint(int u) {
    if(!col[u]) col[u] = 2;
    for(int i = head[u] ; i; i = E[i].next) {
	int v = E[i].to;
	if(!col[v]) {col[v] = col[u] ^ 1;if(!paint(v)) return false;}
	else if(col[v] == col[u]) return false;
    }
    return true;
}
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void Solve() {
    read(N);read(M);
    int u,v;
    for(int i = 1 ; i <= M ; ++i) {
	read(u);read(v);
	add(u,v);add(v,u);
    }
    for(int i = 1 ; i <= N ; ++i) {
	if(!head[i]) ++I;
	else if(!vis[i]){
	    dfs(i);
	    if(paint(i)) ++Q;
	    else ++P;
	}
    }
    int64 ans = 1LL * I * I + 2LL * I * (N - I);
    ans += 1LL * P * P + 2LL * P * Q + 2LL * Q * Q;
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

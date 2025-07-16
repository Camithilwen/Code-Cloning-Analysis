#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 400005
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
struct node {
    int to,next,val;
}E[MAXN * 10];
int head[MAXN],sumE;
int N,M,Ncnt;
int c[MAXN],dis[MAXN];
vector<int> to[MAXN];
bool vis[MAXN];
priority_queue<pii > Q;
void add(int u,int v,int c) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    E[sumE].val = c;
    head[u] = sumE;
}
void Solve() {
    read(N);read(M);
    int q,p;
    Ncnt = M;
    for(int i = 1 ; i <= M ; ++i) {
	read(q);read(p);read(c[i]);
	to[q].pb(i);to[p].pb(i);
    }
    for(int i = 1 ; i <= N ; ++i) {
	sort(to[i].begin(),to[i].end(),[](int a,int b) {return c[a] < c[b];});
	int nw = ++Ncnt;
	for(int j = 0 ; j < to[i].size() ; ++j) {
	    int p = j;
	    while(p < to[i].size() - 1 && c[to[i][p + 1]] == c[to[i][j]]) ++p;
	    for(int h = j + 1 ; h <= p ; ++h) {
		add(to[i][j],to[i][h],0);
		add(to[i][h],to[i][j],0);
	    }
	    add(to[i][j],nw,0);
	    add(nw,to[i][j],1);
	    j = p;
	}
    }
    for(int i = 1 ; i <= Ncnt ; ++i) dis[i] = 1e9;
    for(auto t : to[1]) {dis[t] = 1;Q.push(mp(-1,t));}
    while(!Q.empty()) {
	pii now = Q.top();Q.pop();
	if(vis[now.se]) continue;
	int u = now.se;vis[u] = 1;
	for(int i = head[u] ; i ; i = E[i].next) {
	    int v = E[i].to;
	    if(dis[v] > dis[u] + E[i].val) {
		dis[v] = dis[u] + E[i].val;
		Q.push(mp(-dis[v],v));
	    }
	}
    }
    int ans = 1e9;
    for(auto t : to[N]) ans = min(ans,dis[t]);
    if(ans >= 1e9) {
	puts("-1");return;
    }
    else {out(ans);enter;}
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

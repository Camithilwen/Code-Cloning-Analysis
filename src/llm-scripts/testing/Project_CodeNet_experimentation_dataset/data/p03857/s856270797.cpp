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
map<pii,int> zz;
int N,K,L;
int fa[MAXN],col[MAXN][2],tot;
int getfa(int x) {
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
void Solve() {
    read(N);read(K);read(L);
    for(int i = 1 ; i <= N ; ++i) fa[i] = i;
    int a,b;
    for(int i = 1 ; i <= K ; ++i) {
	read(a);read(b);
	fa[getfa(a)] = getfa(b);
    }
    tot = 0;
    for(int i = 1 ; i <= N ; ++i) {
	if(getfa(i) == i) col[i][0] = ++tot;
    }
    for(int i = 1 ; i <= N ; ++i) col[i][0] = col[getfa(i)][0];
    for(int i = 1 ; i <= N ; ++i) fa[i] = i;
    for(int i = 1 ; i <= L ; ++i) {
	read(a);read(b);
	fa[getfa(a)] = getfa(b);
    }
    tot = 0;
    for(int i = 1 ; i <= N ; ++i) {
	if(getfa(i) == i) col[i][1] = ++tot;
    }
    for(int i = 1 ; i <= N ; ++i) col[i][1] = col[getfa(i)][1];
    for(int i = 1 ; i <= N ; ++i) {
	zz[mp(col[i][0],col[i][1])]++;
    }
    for(int i = 1 ; i <= N ; ++i) {
	out(zz[mp(col[i][0],col[i][1])]);space;
    }
    enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

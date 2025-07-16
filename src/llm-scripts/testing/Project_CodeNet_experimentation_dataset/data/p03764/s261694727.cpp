#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 10005
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
const int MOD = 1000000007;
int N,M,s[2],l[2];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
void Solve() {
    read(N);read(M);
    int x;
    for(int i = 1 ; i <= N ; ++i) {
	read(x);
	x = (x + MOD) % MOD;
	update(l[0],inc(mul(i - 1,x),MOD - s[0]));
	update(s[0],x);
    }
    int y;
    for(int i = 1 ; i <= M ; ++i) {
	read(y);
	y = (y + MOD) % MOD;
	update(l[1],inc(mul(i - 1,y),MOD - s[1]));
	update(s[1],y);
    }
    out(mul(l[0],l[1]));
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}

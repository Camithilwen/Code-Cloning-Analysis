#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 100005
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
int N,A[MAXN];
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}
int check() {
    int c = 0,t;
    for(int i = 1 ; i <= N ; ++i) {
        if(A[i] & 1) {++c;t = A[i];}
    }
    if((N - c) & 1) return 1;
    if(c >= 2 || t == 1) return 0;
    return -1;
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {
        read(A[i]);
    }
    int cnt = 0;
    while(1) {
        int x = check();
        if(x != -1) {
            if((x ^ cnt) == 1) puts("First");
            else puts("Second");
            return;
        }
        cnt ^= 1;
        int g = 0;
        for(int i = 1 ; i <= N ; ++i) {
            if(A[i] & 1) --A[i];
            g = gcd(g,A[i]);
        }
        for(int i = 1 ; i <= N ; ++i) {
            A[i] /= g;
        }
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}

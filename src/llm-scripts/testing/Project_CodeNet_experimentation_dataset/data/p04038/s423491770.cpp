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
const int MOD = 1000000007;
int fac[10000005],invfac[10000005];
int dp[2005][2005],N,K,sum[2005];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
int C(int n,int m) {
    if(n < m) return 0;
    return mul(fac[n],mul(invfac[m],invfac[n - m]));
}
int Query(int n,int m) {
    return C(n + m - 1,m - 1);
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
    read(N);read(K);
    if(K == 1) {puts("1");return;}
    fac[0] = 1;
    for(int i = 1 ; i <= 10000000 ; ++i) fac[i] = mul(fac[i - 1],i);
    invfac[10000000] = fpow(fac[10000000],MOD - 2);
    for(int i = 9999999 ; i >= 0 ; --i) invfac[i] = mul(invfac[i + 1],i + 1);
    dp[1][0] = 1;
    for(int i = 2 ; i <= N ; ++i) {
	int t = (i - 1) * K;
	for(int j = N ; j >= 0 ; --j) sum[j] = inc(sum[j + 1],dp[i - 1][j]);
	for(int j = 0 ; j <= i ; ++j) {
	    update(dp[i][j],mul(sum[max(0,j - 1)],Query(K - 2,t - j + 1)));
	}
    }
    int ans = 0;
    for(int j = 0 ; j <= N ; ++j) update(ans,mul(dp[N][j],fac[N]));
    out(ans);enter;
}

int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
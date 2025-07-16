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
int H,W;
char s[105][105];
int sum[105][105],a,b;
int dp[2][105][105][105],ans;
int query(int x1,int y1,int x2,int y2) {
    
    x2 = min(H,x2);y2 = min(W,y2);
    if(x1 > x2 || y1 > y2) return 0;
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
void update(int &x,int y) {
    x = max(x,y);
}
void Solve() {
    read(H);read(W);
    for(int i = 1 ; i <= H ; ++i) scanf("%s",s[i] + 1);
    for(int i = 1 ; i <= H ; ++i) {
	for(int j = 1 ; j <= W ; ++j) {
	    sum[i][j] = (s[i][j] == 'o');
	    sum[i][j] += sum[i][j - 1];
	    if(s[i][j] == 'E') {a = i;b = j;}
	}
    }
    for(int i = 1 ; i <= H ; ++i) {
	for(int j = 1 ; j <= W ; ++j) {
	    sum[i][j] += sum[i - 1][j];
	}
    }
    int cur = 0;
    dp[0][0][0][0] = 0;
    for(int i = 0 ; i < a ; ++i) {
	memset(dp[cur ^ 1],0,sizeof(dp[cur ^ 1]));
	for(int j = 0 ; j < b ; ++j) {
	    for(int k = 0 ; k <= H - a ; ++k) {
		for(int t = 0 ; t <= W - b ; ++t) {
		    ans = max(ans,dp[cur][j][k][t]);
		    int tmp = dp[cur][j][k][t];
		    if(k < a - i - 1) tmp += query(a - i - 1,max(b - j,t + 1),a - i - 1,min(b + t,W - j));
		    update(dp[cur ^ 1][j][k][t],tmp);
		    tmp = dp[cur][j][k][t];
		    if(t < b - j - 1) tmp += query(max(a - i,k + 1),b - j - 1,min(a + k,H - i),b - j - 1);
		    update(dp[cur][j + 1][k][t],tmp);
		    tmp = dp[cur][j][k][t];
		    if(H - i >= a + k + 1) tmp += query(a + k + 1,max(b - j,t + 1),a + k + 1,min(b + t,W - j));
		    update(dp[cur][j][k + 1][t],tmp);
		    tmp = dp[cur][j][k][t];
		    if(W - j >= b + t + 1) tmp += query(max(a - i,k + 1),b + t + 1,min(a + k,H - i),b + t + 1);
		    update(dp[cur][j][k][t + 1],tmp);
		}
	    }
	}
	cur ^= 1;
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
